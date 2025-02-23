import os
import time
import re
import logging
import discord
from dotenv import load_dotenv
from llama_cpp import Llama
from collections import defaultdict
from datetime import datetime, timedelta, timezone

os.environ['CUDA_VISIBLE_DEVICES'] = '0'
MODEL_PATH = "./models/deepseek-14b-Q4_K_M.gguf"
load_dotenv()
TOKEN = os.getenv('DISCORD_TOKEN')
TARGET_CHANNEL_ID = 1343075595520835694

llm = Llama(
    model_path=MODEL_PATH,
    n_gpu_layers=99,
    n_ctx=8192,
    n_batch=2048,
    n_threads=12,
    n_threads_batch=12,
    main_gpu=0,
    offload_kqv=True,
    mul_mat_q=True,
    flash_attn=True,
    verbose=False,
)

class ConversationManager:
    def __init__(self, max_age_minutes=60, max_messages=30):
        self.conversations = defaultdict(list)
        self.max_age = timedelta(minutes=max_age_minutes)
        self.max_messages = max_messages

    def add_message(self, channel_id: int, role: str, content: str):
        current_time = datetime.now(timezone.utc)
        self.conversations[channel_id].append({
            'role': role,
            'content': content,
            'timestamp': current_time
        })
        self._cleanup_old_messages(channel_id)
        while self._calculate_total_tokens(channel_id) > 7168:
            self.conversations[channel_id].pop(0)

    def clear_conversation(self, channel_id: int = None):
        if channel_id is None:
            self.conversations.clear()
        else:
            if channel_id in self.conversations:
                self.conversations[channel_id].clear()

    def get_recent_conversation(self, channel_id: int) -> list:
        self._cleanup_old_messages(channel_id)
        return self.conversations[channel_id]

    def _cleanup_old_messages(self, channel_id: int):
        current_time = datetime.now(timezone.utc)
        self.conversations[channel_id] = [
            msg for msg in self.conversations[channel_id]
            if current_time - msg['timestamp'] <= self.max_age
        ]

    def _calculate_total_tokens(self, channel_id: int) -> int:
        return sum(
            len(llm.tokenize(msg['content'].encode())) 
            for msg in self.conversations[channel_id]
        )

    async def load_history_from_channel(self, channel: discord.TextChannel):
        """Discord チャンネルの過去メッセージを取得して履歴に読み込む
           ロールは、botの場合 "assistant"、それ以外は "user" とする。
        """
        messages = []
        async for message in channel.history(limit=self.max_messages):
            role = "assistant" if message.author.bot else "user"
            messages.append({
                'role': role,
                'content': message.content,
                'timestamp': message.created_at  # 既に offset-aware (UTC)
            })
        messages = list(reversed(messages))
        self.conversations[channel.id] = messages

def generate_response(channel_id: int, prompt: str) -> str:
    start_time = time.time()
    try:
        conversation_history = conversation_manager.get_recent_conversation(channel_id)
        messages = [
            {"role": "system", "content": "制約に従ってください。(あなたは話し相手です。自然な日本語で会話してください。あくまでも会話なので、簡潔に返事してください。返答だけを出力。あいまいな応答や話題の反復を避ける。過去の会話を参照して一貫性のある対話を維持。)"}
        ]
        for msg in conversation_history:
            messages.append({"role": msg['role'], "content": msg['content']})
        messages.append({"role": "user", "content": prompt})

        output = llm.create_chat_completion(
            messages=messages,
            max_tokens=1024,
            temperature=0.8,
            top_p=0.95,
            top_k=40,
            repeat_penalty=1.15,
            frequency_penalty=0.25,
            presence_penalty=0.25,
            stop=["</s>", "システム:", "ユーザー:"],
            stream=True
        )
        response_text = ""
        for chunk in output:
            if 'choices' in chunk and len(chunk['choices']) > 0:
                delta = chunk['choices'][0]['delta']
                if 'content' in delta:
                    response_text += delta['content']
                    print(f"受信チャンク: {delta['content']}")

        discord_response = re.sub(r'<think>.*?</think>', '', response_text, flags=re.DOTALL).strip()
        
        end_time = time.time()
        processing_time = end_time - start_time
        print(f"最終応答:\n{response_text}")
        print(f"処理時間: {processing_time:.2f}秒")
        return discord_response
    except Exception as e:
        print(f"応答生成エラー: {str(e)}")
        raise

intents = discord.Intents.default()
intents.message_content = True
client = discord.Client(intents=intents)
conversation_manager = ConversationManager(max_age_minutes=10, max_messages=10)

@client.event
async def on_ready():
    print(f'{client.user} としてログインしました')
    print(f'対象チャンネルID: {TARGET_CHANNEL_ID}')
    channel = client.get_channel(TARGET_CHANNEL_ID)
    if channel is not None:
        await conversation_manager.load_history_from_channel(channel)
        print("過去の会話履歴を読み込みました")
    else:
        print("対象チャンネルが見つかりませんでした")

@client.event
async def on_message(message):
    if message.author == client.user:
        return

    if message.content.strip() == "!reset":
        conversation_manager.clear_conversation(message.channel.id)
        await message.channel.send("会話履歴をリセットしました。")
        return

@client.event
async def on_message(message):
    if message.author == client.user:
        return

    should_respond = False
    user_input = ""
    try:
        if client.user in message.mentions:
            should_respond = True
            user_input = message.content.replace(f'<@{client.user.id}>', '').strip()
        elif message.channel.id == TARGET_CHANNEL_ID:
            should_respond = True
            user_input = message.content.strip()
        if should_respond and user_input:
            print(f"メッセージ受信: {user_input}")
            conversation_manager.add_message(
                message.channel.id,
                "user",
                user_input
            )
            async with message.channel.typing():
                try:
                    response = generate_response(message.channel.id, user_input)
                    conversation_manager.add_message(
                        message.channel.id,
                        "assistant",
                        response
                    )
                    await message.reply(response)
                    print(f"応答送信完了: {response}")
                except Exception as e:
                    error_msg = f"エラーが発生しました: {str(e)}"
                    print(error_msg)
                    await message.reply("申し訳ありません。応答の生成中にエラーが発生しました。しばらく待ってから再度お試しください。")
    except Exception as e:
        print(f"メッセージ処理エラー: {str(e)}")

if __name__ == "__main__":
    try:
        client.run(TOKEN, log_level=logging.WARNING)  # Discordのログレベルも設定
    except discord.errors.LoginFailure:
        print("トークンが無効です。.envファイルのDISCORD_TOKENを確認してください。")
    except Exception as e:
        print(f"エラーが発生しました: {e}")
