<?php

    $session_out = "<input type='button' value='Deconnexion' onclick='session_out()'/>";
    session_start();
    if(session_id()){
        echo "Hello World";
        echo $session_out;
        if($session_out.isClicked()){
            header("Location: index.html");
        }
    }
    else{
        header("Location: index.html");
    }
    
?>