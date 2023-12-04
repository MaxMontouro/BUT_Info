<?php

    //On définit le mot de passe et le login de base
    $login_valide = "admin";
    $passwd_valide = "admin";

    $passwd_crypter = crypt($passwd_valide, "RSA");


    //on recupere les données saisie
    $login_saisie = $_POST["login"];
    $passwd_saisie = $_POST["password"];

    $passwd_saisie_crypt = crypt($passwd_saisie, "RSA");

    //on test si les données saisie sont valide
        if($login_saisie == $login_valide && $passwd_crypter == $passwd_saisie_crypt){
            echo "Bienvenue " . $login_saisie;
            session_start();

            //on enregistre les données dans la session
            $_SESSION["login"] = $login_saisie;
            $_SESSION["passwd"] = $passwd_saisie_crypt;

            //redirection vers la page a renvoyer
            header("Location: renvoyer.php");

        }else{
            echo "Erreur de login ou de mot de passe";
        }
        
?>