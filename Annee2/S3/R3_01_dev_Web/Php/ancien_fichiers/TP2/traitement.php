<?php

if($_SERVER["REQUEST_METHOD"]=== "POST"){

    echo "Bonjour <br>";


    $nom = $_POST['nom'];
    $age = $_POST['age'];
    $mail = $_POST['mail'];
    $don = $_POST['don'];



    $ligne = " $nom | $age | $mail | $don".PHP_EOL;
    file_put_contents("resultats.txt", $ligne, FILE_APPEND);


    echo "Nom : $nom | ";
    echo "Age : $age | ";
    echo "Mail : $mail | ";
    echo "Don : $don | <br>";
}


?>






