<?php
header('Content-type: image/png');

// Connexion à la base de données (remplacer par vos paramètres de connexion)
$servername = "lakartxela.iutbayonne.univ-pau.fr";
$username = "roose";
$password = "roose";
$dbname = "roose";

$conn = new mysqli($servername, $username, $password, $dbname);

if ($conn->connect_error) {
    die("Échec de la connexion: " . $conn->connect_error);
}

// Requête SQL pour récupérer les données
$sql = "SELECT ville, indice FROM bourse ORDER BY ville DESC"; // DESC pour que New York apparaisse en premier
$result = $conn->query($sql);

// Initialisation de l'image
$width = 1000;
$bar_width = 50;
$height = 1000;

$image = imagecreatetruecolor($width, $height);

// Définition des couleurs
$red = imagecolorallocate($image, 255, 0, 0);
$blue = imagecolorallocate($image, 0, 0, 255);
$green = imagecolorallocate($image, 0, 255, 0);
$white = imagecolorallocate($image, 255, 255, 255);
$black = imagecolorallocate($image, 0, 0, 0);

// Fond de l'image
imagefill($image, 0, 0, $red);

// Vérifier les données et les afficher
if ($result->num_rows > 0) {
    $x = 10; // Position initiale de la première barre
    while($row = $result->fetch_assoc()) {
        $y = ($height - ($row["indice"] * 10)); // Hauteur de la barre basée sur l'indice
        
        if($row["ville"] == "Paris")
            $color = $blue;
        else if($row["ville"] == "NY")
            $color = $green;
        else
            $color = $black;

        // Dessiner la barre
        imagefilledrectangle($image, $x, $y, $x + $bar_width, $height, $color);

        // Ajouter le texte
        imagestringup($image, 5, $x +10, $y - 20, $row["ville"]." - ". $row["indice"], $white);

        $x += $bar_width + 10; // Décaler la position x pour la prochaine barre
    }
}

// Envoi de l'image
imagepng($image);
imagedestroy($image);
?>