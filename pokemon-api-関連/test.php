<?php
function getPokemonById($id) {
    $query = <<<GRAPHQL
    query getPokemon(\$id: Int!) {
        pokemon_v2_pokemon_by_pk(id: \$id) {
            name
            id
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
?>

<!DOCTYPE html>
<html>
<head>
    <meta charset="UTF-8">
    <title>Pokemon Debug</title>
</head>
<body>
    <form method="POST">
        <input type="number" name="pokemon_id" placeholder="Enter Pokemon ID">
        <input type="submit" value="Search">
    </form>

    <?php
    if ($_SERVER['REQUEST_METHOD'] === 'POST' && !empty($_POST['pokemon_id'])) {
        $pokemon = getPokemonById($_POST['pokemon_id']);
        echo '<h3>Raw Response:</h3>';
        echo '<pre>';
        print_r($pokemon);
        echo '</pre>';
    }
    ?>
</body>
</html>