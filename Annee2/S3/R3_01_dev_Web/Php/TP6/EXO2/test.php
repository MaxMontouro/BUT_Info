<?php
    $dom = new DOMDocument();
    $dom->load("test.xml");
    $listPays = $dom->getElementsByTagName("pays");
    $array = [];
    foreach($listPays as $pays){
        if(str_contains(strtolower($pays->nodeValue), $_GET["nomPays"])){
            array_push($array, $pays->nodeValue);
        }
    }

    header('Content-Type: application/json');
    echo json_encode($array);
?>