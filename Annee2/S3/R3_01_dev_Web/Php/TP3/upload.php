<?php
$uploadDir = 'upload/';
if (!file_exists($uploadDir)) {
    mkdir($uploadDir, 0777, true);
}

if ($_SERVER["REQUEST_METHOD"] === "POST" && isset($_POST["nbPhotos"])) {
    $nbPhotos = intval($_POST["nbPhotos"]);

    for ($i = 1; $i <= $nbPhotos; $i++) {
        $photoName = "photo$i";
        if (isset($_FILES[$photoName]) 
                && $_FILES[$photoName]['error'] === UPLOAD_ERR_OK) {
            $tmpName = $_FILES[$photoName]['tmp_name'];
            $fileName = basename($_FILES[$photoName]['name']);
            $destination = $uploadDir . $fileName;

            if (move_uploaded_file($tmpName, $destination)) {
                echo "La photo $i a été uploadée avec succès.<br>";
            } else {
                echo "Erreur lors de l'upload de la photo $i.<br>";
            }
        } else {
            echo "Erreur ou pas de fichier pour la photo $i.<br>";
        }
    }
} else {
    echo 'Veuillez soumettre le formulaire.';
}
?>