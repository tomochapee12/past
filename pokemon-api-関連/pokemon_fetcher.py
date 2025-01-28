import requests
import mysql.connector
from mysql.connector import Error
from typing import List, Dict, Any
import argparse
import os
import time

class PokemonDataFetcher:
    def __init__(self):
        """データベース接続の初期化"""
        self.base_url = "https://pokeapi.co/api/v2/pokemon"
        
        # コマンドライン引数の設定
        parser = argparse.ArgumentParser(description='Pokemon Data Fetcher')
        parser.add_argument('--password', help='MySQL root password')
        parser.add_argument('--database', default='pokemon_db', help='Database name (default: pokemon_db)')
        args = parser.parse_args()

        # パスワードの取得（コマンドライン引数 or 環境変数）
        self.password = args.password or os.getenv('MYSQL_PASSWORD')
        if not self.password:
            self.password = input("Enter MySQL root password: ")

        self.db_config = {
            "host": "localhost",
            "user": "root",
            "password": self.password,
            "database": args.database
        }

    def initialize_database(self) -> None:
        """データベースの初期化"""
        try:
            # データベースがない場合は作成
            conn = mysql.connector.connect(
                host="localhost",
                user="root",
                password=self.password
            )
            cursor = conn.cursor()
            cursor.execute(f"CREATE DATABASE IF NOT EXISTS {self.db_config['database']}")
            conn.close()

            # 作成したデータベースに接続してテーブル作成
            connection = mysql.connector.connect(**self.db_config)
            cursor = connection.cursor()

            # ポケモンの基本情報テーブル
            cursor.execute("""
                CREATE TABLE IF NOT EXISTS pokemon (
                    id INT PRIMARY KEY,
                    name VARCHAR(100) NOT NULL,
                    height INT,
                    weight INT,
                    pre_evolution_id INT,
                    FOREIGN KEY (pre_evolution_id) REFERENCES pokemon(id)
                ) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci
            """)

            # タイプ情報テーブル
            cursor.execute("""
                CREATE TABLE IF NOT EXISTS pokemon_types (
                    pokemon_id INT,
                    type_name VARCHAR(50),
                    slot INT,
                    PRIMARY KEY (pokemon_id, type_name),
                    FOREIGN KEY (pokemon_id) REFERENCES pokemon(id)
                ) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci
            """)

            # アビリティ情報テーブル
            cursor.execute("""
                CREATE TABLE IF NOT EXISTS pokemon_abilities (
                    pokemon_id INT,
                    ability_name VARCHAR(100),
                    is_hidden BOOLEAN,
                    slot INT,
                    PRIMARY KEY (pokemon_id, ability_name),
                    FOREIGN KEY (pokemon_id) REFERENCES pokemon(id)
                ) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci
            """)

            connection.commit()
            print(f"Database and tables initialized successfully.")

        except Error as e:
            print(f"Error initializing database: {e}")
        finally:
            if 'connection' in locals() and connection.is_connected():
                cursor.close()
                connection.close()

    def fetch_pokemon_data(self, pokemon_id: int) -> Dict[str, Any]:
        """
        PokeAPIからポケモンデータを取得
        
        Args:
            pokemon_id: ポケモンのID
        """
        try:
            response = requests.get(f"{self.base_url}/{pokemon_id}")
            response.raise_for_status()
            return response.json()
        except requests.exceptions.RequestException as e:
            print(f"Error fetching pokemon {pokemon_id}: {e}")
            return None

    def insert_pokemon_data(self, pokemon_data: Dict[str, Any]) -> None:
        """
        ポケモンデータをデータベースに挿入
        
        Args:
            pokemon_data: PokeAPIから取得したデータ
        """
        try:
            connection = mysql.connector.connect(**self.db_config)
            cursor = connection.cursor()

            # 基本情報の挿入
            cursor.execute("""
                INSERT INTO pokemon (id, name, height, weight)
                VALUES (%s, %s, %s, %s)
                ON DUPLICATE KEY UPDATE
                    name = VALUES(name),
                    height = VALUES(height),
                    weight = VALUES(weight)
            """, (
                pokemon_data['id'],
                pokemon_data['name'],
                pokemon_data['height'],
                pokemon_data['weight']
            ))

            # タイプ情報の挿入
            cursor.execute("DELETE FROM pokemon_types WHERE pokemon_id = %s", (pokemon_data['id'],))
            for type_info in pokemon_data['types']:
                cursor.execute("""
                    INSERT INTO pokemon_types (pokemon_id, type_name, slot)
                    VALUES (%s, %s, %s)
                """, (
                    pokemon_data['id'],
                    type_info['type']['name'],
                    type_info['slot']
                ))

            # アビリティ情報の挿入
            cursor.execute("DELETE FROM pokemon_abilities WHERE pokemon_id = %s", (pokemon_data['id'],))
            for ability_info in pokemon_data['abilities']:
                cursor.execute("""
                    INSERT INTO pokemon_abilities (pokemon_id, ability_name, is_hidden, slot)
                    VALUES (%s, %s, %s, %s)
                """, (
                    pokemon_data['id'],
                    ability_info['ability']['name'],
                    ability_info['is_hidden'],
                    ability_info['slot']
                ))

            connection.commit()
            print(f"Successfully inserted data for Pokemon {pokemon_data['id']} ({pokemon_data['name']})")

        except Error as e:
            print(f"Error inserting pokemon data: {e}")
        finally:
            if connection.is_connected():
                cursor.close()
                connection.close()

    def fetch_and_store_pokemon_range(self, start_id: int, end_id: int) -> None:
        """
        指定範囲のポケモンデータを取得して保存
        
        Args:
            start_id: 開始ID
            end_id: 終了ID
        """
        for pokemon_id in range(start_id, end_id + 1):
            print(f"Fetching pokemon {pokemon_id}...")
            pokemon_data = self.fetch_pokemon_data(pokemon_id)
            if pokemon_data:
                self.insert_pokemon_data(pokemon_data)
                time.sleep(1)  # APIレート制限を考慮した待機時間
            print(f"Completed pokemon {pokemon_id}")

def main():
    fetcher = PokemonDataFetcher()
    fetcher.initialize_database()
    
    # 取得したいポケモンの範囲を指定
    start_id = int(input("Enter start Pokemon ID (e.g., 1): "))
    end_id = int(input("Enter end Pokemon ID (e.g., 200): "))
    
    fetcher.fetch_and_store_pokemon_range(start_id, end_id)

if __name__ == "__main__":
    main()