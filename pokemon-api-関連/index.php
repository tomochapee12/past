<?php
session_start();

if (!isset($_SESSION['pokemon_history'])) {
    $_SESSION['pokemon_history'] = [];
}

function getPokemonById($id){
    $query = <<<GRAPHQL
    query getPokemonWithClassification(\$id: Int!) {
        pokemon_v2_pokemon_by_pk(id: \$id) {
            name
            id
            height
            weight
            pokemon_v2_pokemontypes {
                pokemon_v2_type {
                    name
                }
            }
            pokemon_v2_pokemonabilities {
                pokemon_v2_ability {
                    name
                }
            }
            pokemon_v2_pokemonspecy {
                name
                pokemon_v2_pokemonspeciesnames(where: {language_id: {_eq: 1}}) {
                    genus
                }
            }
        }
    }
    GRAPHQL;

    $data = json_encode([
        'query' => $query,
        'variables' => ['id' => (int)$id]
    ]);

    $ch = curl_init('https://beta.pokeapi.co/graphql/v1beta');
    curl_setopt($ch, CURLOPT_RETURNTRANSFER, true);
    curl_setopt($ch, CURLOPT_HTTPHEADER, ['Content-Type: application/json']);
    curl_setopt($ch, CURLOPT_POST, true);
    curl_setopt($ch, CURLOPT_POSTFIELDS, $data);

    $response = curl_exec($ch);
    curl_close($ch);

    return json_decode($response, true);
}
function displayPokemon($pokemonData) {
    $imageUrl = sprintf(
        'https://raw.githubusercontent.com/PokeAPI/sprites/master/sprites/pokemon/%d.png',
        $pokemonData['id']
    );
    
    $classification = $pokemonData['pokemon_v2_pokemonspecy']['pokemon_v2_pokemonspeciesnames'][0]['genus'] ?? '不明';
    ?>
    <div style="border: 1px solid #ccc; margin: 10px 0; padding: 10px;">
        <h2>名前: <?php echo htmlspecialchars(ucfirst($pokemonData['name'])); ?></h2>
        <img src="<?php echo $imageUrl; ?>" alt="<?php echo htmlspecialchars($pokemonData['name']); ?>">
        <p>分類: <?php echo htmlspecialchars($classification); ?></p>
        <p>タイプ: 
            <?php
            foreach ($pokemonData['pokemon_v2_pokemontypes'] as $type) {
                echo htmlspecialchars($type['pokemon_v2_type']['name']) . ' ';
            }
            ?>
        </p>
        <p>高さ: <?php echo ($pokemonData['height'] / 10); ?>m</p>
        <p>重さ: <?php echo ($pokemonData['weight'] / 10); ?>kg</p>
        <p>特性: 
            <?php
            foreach ($pokemonData['pokemon_v2_pokemonabilities'] as $ability) {
                echo htmlspecialchars($ability['pokemon_v2_ability']['name']) . ' ';
            }
            ?>
        </p>
    </div>
    <?php
}
?>
<!DOCTYPE html>
<html>
<head>
    <meta charset="UTF-8">
    <title>ポケモン検索</title>
</head>
<body>
    <form method="POST">
        <input type="number" name="pokemon_id" placeholder="ポケモンのIDを入力">
        <input type="submit" value="検索">
    </form>

    <?php
    if ($_SERVER['REQUEST_METHOD'] === 'POST' && !empty($_POST['pokemon_id'])) {
        $pokemon = getPokemonById($_POST['pokemon_id']);
        if($pokemon && isset($pokemon['data']['pokemon_v2_pokemon_by_pk'])){
            $pokemonData = $pokemon['data']['pokemon_v2_pokemon_by_pk'];
            array_unshift($_SESSION['pokemon_history'], $pokemonData);
            $_SESSION['pokemon_history'] = array_slice($_SESSION['pokemon_history'], 0, 10);
            displayPokemon($pokemonData);
        }else{
            echo '<p>ポケモンが見つかりませんでした。</p>';
        }
    }

    if(!empty($_SESSION['pokemon_history'])){
        echo '<h3>検索履歴</h3>';
        foreach ($_SESSION['pokemon_history'] as $historicalPokemon){
            displayPokemon($historicalPokemon);
        }
    }
    ?>

    <form method="POST" style="margin-top: 20px;">
        <input type="submit" name="clear_history" value="履歴をクリア">
    </form>

    <?php
    if(isset($_POST['clear_history'])){
        $_SESSION['pokemon_history'] = [];
    }
    ?>
</body>
</html>