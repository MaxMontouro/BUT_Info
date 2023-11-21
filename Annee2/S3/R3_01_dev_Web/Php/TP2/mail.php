<?php

if($_SERVER["REQUEST_METHOD"]=== "POST"){
    // lire le fichier des resultats
    $contenu = file_get_contents('resultats.txt');
    $lignes = explode(PHP_EOL, $contenu);

    // Init les variables pour les calculs
    $sommeDons = 0;
    $sommeAges = 0;
    $nbDonneurs = 0;

    // Premiere boucle pour calculer les totaux
    foreach($lignes as $ligne){
        if(!empty($lignes)){
            list($nom, $age, $mail, $don) = explode(' | ', $ligne);
                $sommeDons += ($don);
                $sommeAges += ($age);
                $nbDonneurs++;
        }
    }

    // verifier qu'il y a des donneurs
    if($nbDonneurs > 0){
        //deuxieme boucle pour envoyer les mails
        foreach($lignes as $ligne){
            if(!empty($ligne)){
                list($nom, $age, $mail, $don) = explode(' | ', $ligne);

                $sujet = "Merci de votre don , vous etes kawai UWU";
                $message = "Cher(e) $nom,\n";
                $message .= "Et merce pour le don $don,\n";
                $message .= "La somme totale est de $sommeDons,\n";
                $message .= "chef merci du soutien.\n";
                $message .= "L'équipe";

                mail($mail, $sujet, $message);
                
                echo "<p>Email envoyé à $nom ($mail):</p>";
                echo "<pre>$message</pre>";
            }
        }
    }
}
?>