<?php
header("Content-type: image/png");

$bdd = "roose";
$host = "lakartxela.iutbayonne.univ-pau.fr";
$user = "roose";
$pass = "roose";

$nomTable = "bourse";
//print "Tentative de connexion sur site bd <br>";

$link = mysqli_connect($host, $user, $pass, $bdd) or die("Impossibe de se connecter à la BD");

//echo "Tout c'est bien passé <br><br>";



if(mysqli_connect_errno()){
    //echo "Failed to connect to MYSQL : " . mysqli_connect_errno();
    exit();
};

//on genere l'image avant la requete car on va utiliser les résultats pour l image 

$sql = "SELECT ville, indice FROM bourse ORDER BY ville";
$result = $link->query($sql);

$indiceX = 10;
$indiceY = 10;
$police = imageloadfont("helvetica");


$image = imagecreatetruecolor(1000,1000);
$couleur = imagecolorallocate($image, 255,0,0);
imagefill($image,0,0,$couleur);
$blanc = imagecolorallocate($image,0,0,0);

// Affichage des données
if ($result->num_rows > 0) {
    while($row = $result->fetch_assoc()) {
        //echo "Ville: " . $row["ville"]. " - Indice: " . $row["indice"]. "<br>";
        imagecharup($image, $police, 10,10, $row["ville"],$blanc);
        $indiceX += 100;
        $indiceY += 100;
    }
} else {
    //echo "0 résultats";
}


imagepng($image);
imagedestroy($image);

mysqli_close($link);

?>