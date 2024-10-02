package com.Maks.Jeu;

import java.util.ArrayList;
import java.util.List;

public class Personnage {

    public static String[] direction = {"Nord", "Est", "Sud", "Ouest"};

    public static String tourner(int fois){

        String reponse = "";

        fois = fois%4;

        switch(fois){
            case 1:
                reponse = "Nord";
                break;

            case 2:
                reponse = "Est";
                break;

            case 3:
                reponse = "Sud";
                break;

            case 4:
                reponse = "Ouest";
                break;

            default:
                reponse = "Nord";
                break;
        }

        return reponse;
    }
}
