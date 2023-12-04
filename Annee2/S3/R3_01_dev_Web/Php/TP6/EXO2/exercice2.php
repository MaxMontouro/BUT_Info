<?php

    $dom = new DOMDocument();
    $dom->load("test.xml");
    $listPays = $dom->getElementsByTagName("pays");


    //recuperation des données de l html
    if($_SERVER["REQUEST_METHOD"] == "POST"){
        $nomPays = $_POST["nomPays"];
        foreach($listPays as $pays){
            if($nomPays == $pays->firstChild->nodeValue){
                echo $nomPays;
            }
        }
    }

    //generation de l'html
    $vari = '<!DOCTYPE html>
    <html lang="fr">
    <head>
        <meta charset="UTF-8">
        <meta http-equiv="X-UA-Compatible" content="IE=edge">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <title>TestPHP</title>
    </head>
    <body>
        <form action="exercice2.php" method="post"> 
            <label for="nomPays"> Nom du pays: </label>
            <input type="text" id="nomPays" name = "nomPays"><br>
            <input type="submit" value="Soumettre"> </input>
        </form>
    </body>
    </html>';

    echo $vari;
?>