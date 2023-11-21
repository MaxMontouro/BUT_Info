<?php 
    $file = fopen("restos.csv", "r");

 
    while (($line = fgetcsv($file, 1000, ";")) !== FALSE){
        echo "Nom : $line[0]<br>";
        echo "Prénom : $line[1]<br>";
        echo "Restaurant : $line[2]<br>";
        echo "<br>";
    }

fclose($file);
?>