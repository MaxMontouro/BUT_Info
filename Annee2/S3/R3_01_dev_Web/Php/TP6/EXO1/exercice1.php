<?php
    $dom = new DomDocument;
    $dom->load("test.xml");
    $listePays = $dom->getElementsByTagName('pays');
    
    foreach($listePays as $pays){
        echo $pays->firstChild->nodeValue . "<br />";
    }

    echo "---<br />";

    $europe = $dom->getElementsByTagName('europe')->item(0);
    $listePaysEurope = $europe->getElementsByTagName('pays');
    
    foreach($listePaysEurope as $pays){
        echo $pays->firstChild->nodeValue . "<br />";
    }
?>