<?php
try {
    $conn = new PDO("mysql:host=localhost;dbname=pokemon_db;charset=utf8", "root", "---");
    $conditions = [];
    $params = [];
    if ($_SERVER["REQUEST_METHOD"] == "POST") {
        if (!empty($_POST['name'])) {
            $conditions[] = "p.name LIKE ?";
            $params[] = "%" . $_POST['name'] . "%";
        }
        if (!empty($_POST['type'])) {
            $conditions[] = "pt.type_name LIKE ?";
            $params[] = "%" . $_POST['type'] . "%";
        }
        if (!empty($_POST['ability'])) {
            $conditions[] = "pa.ability_name LIKE ?";
            $params[] = "%" . $_POST['ability'] . "%";
        }
    }
    $sql = "SELECT DISTINCT p.id, p.name, p.height, p.weight,
                GROUP_CONCAT(DISTINCT pt.type_name) as types,
                GROUP_CONCAT(DISTINCT pa.ability_name) as abilities
            FROM pokemon p
            LEFT JOIN pokemon_types pt ON p.id = pt.pokemon_id
            LEFT JOIN pokemon_abilities pa ON p.id = pa.pokemon_id";
    
    if (!empty($conditions)) {
        $sql .= " WHERE " . implode(" AND ", $conditions);
    }
    
    $sql .= " GROUP BY p.id ORDER BY p.id";
    
    $stmt = $conn->prepare($sql);
    $stmt->execute($params);
}catch(PDOException $e){
    // エラーが発生した場合，終了
    exit($e ->getMessage());
}
?>
<!DOCTYPE html>
<html>
<head>
    <meta charset="utf-8">
    <title>ポケモン検索</title>
</head>
<body>
    <center>
        <h2>ポケモン検索</h2>
        <div class="search">
            <form method="POST">
                <div class="search-field">
                    名前：<input type="text" name="name" value="<?php echo isset($_POST['name']) ? htmlspecialchars($_POST['name']) : ''; ?>">
                </div>
                <div class="search-field">
                    タイプ：<input type="text" name="type" value="<?php echo isset($_POST['type']) ? htmlspecialchars($_POST['type']) : ''; ?>">
                </div>
                <div class="search-field">
                    特性：<input type="text" name="ability" value="<?php echo isset($_POST['ability']) ? htmlspecialchars($_POST['ability']) : ''; ?>">
                </div>
                <input type="submit" value="検索">
            </form>
        </div>
            <?php if ($stmt->rowCount() > 0): ?>
                <table>
                    <tr>
                        <th>ID</th>
                        <th>名前</th>
                        <th>タイプ</th>
                        <th>特性</th>
                        <th>高さ(dm)</th>
                        <th>重さ(hg)</th>
                    </tr>
                    <?php while ($row = $stmt->fetch(PDO::FETCH_ASSOC)): ?>
                        <tr>
                            <td><?php echo htmlspecialchars($row['id']); ?></td>
                            <td><?php echo htmlspecialchars($row['name']); ?></td>
                            <td><?php echo htmlspecialchars($row['types']); ?></td>
                            <td><?php echo htmlspecialchars($row['abilities']); ?></td>
                            <td><?php echo htmlspecialchars($row['height']); ?></td>
                            <td><?php echo htmlspecialchars($row['weight']); ?></td>
                        </tr>
                    <?php endwhile; ?>
                </table>
            <?php else: ?>
                <p>検索結果が見つかりませんでした。</p>
            <?php endif; ?>
    </center>
</body>
</html>