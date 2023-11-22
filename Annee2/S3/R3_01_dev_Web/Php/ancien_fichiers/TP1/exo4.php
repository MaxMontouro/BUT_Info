<?php
/*
if(file_exists('compteur_general.txt'))

{ $compteur_f = fopen('compteur_general.txt', 'r+');$compte = fgets($compteur_f);}

else

{ $compteur_f = fopen('compteur_general.txt', 'a+'); $compte = 0;} //a+ permission de fichier

$compte++;

fseek($compteur_f, 0);

fputs($compteur_f, $compte);

fclose($compteur_f);

echo $compte.' visites';
*/
$file = 'counter.txt';

// lire la valeur actuell du compteur
$count = file_get_contents($file);
$count = empty($count) ? 0 : intval($count);// convertit count en entier;
// ? : c'est un if

$count++;

file_put_contents($file, $count);

echo "<blue><strong> Nombre de visites : $count </strong></blue>";
?>