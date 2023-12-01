<?php
    $file_ini = "./config.ini";
    $fichier = parse_ini_file($file_ini, true);

    $fieldNames = array_keys($fichier["NOMS"]);
    $nombreChamps = array_keys($fichier["NB"])[0];
    $nomFic = array_keys($fichier["NOMFIC"])[0];


    //move_uploaded_file();
    $champs = ""; 

    foreach($fieldNames as $fieldName){
        $champs .= "<label for='{$fieldName}'> {$fieldName}: </label>\n";
        $champs .= "<input type='text' id='{$fieldName}' name = '{$fieldName}'><br>\n";
    } 



    $vari = '<!DOCTYPE html>
    <html lang="fr">
    <head>
        <meta charset="UTF-8">
        <meta http-equiv="X-UA-Compatible" content="IE=edge">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <title>TestPHP</title>
    </head>
    <body>
        <form action="'.$nomFic.'.php" method="post"> 
            '.$champs.'
            <input type="submit" value="Soumettre"> </input>
        </form>
    </body>
    </html>';

    


    $phpFile = "<?php\n";
    $phpFile .= 'if($_SERVER["REQUEST_METHOD"] == "POST"){';

    foreach($fieldNames as $fieldName){
        $phpFile .= 'echo $_POST["'.$fieldName.'"]."<br>";';

    }

    $phpFile .= "}\n?>";

    $file = fopen("./".$nomFic.".php", "w");
    fwrite($file,$phpFile);
    fclose($file);

    echo $vari;
?>