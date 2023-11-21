<?php
// EXO1
    echo "Hello world<P>";

// EXO2
    // récupère l'adresse ip du visiteur
    $ip = $_SERVER['REMOTE_ADDR'];

    // saut de ligne
    

    $deb = intval(explode('.',$ip)[0]);

    if($deb < 128){
        $classe = "A";
    } 
    elseif($deb < 192){
        $classe = "B";
    } 
    else{
        $classe = "C";
    }

    echo "Adresse : $ip (classe $classe)";
?>