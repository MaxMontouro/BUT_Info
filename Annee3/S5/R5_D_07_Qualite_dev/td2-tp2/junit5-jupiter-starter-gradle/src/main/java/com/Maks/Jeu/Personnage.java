package com.Maks.Jeu;

import java.util.ArrayList;
import java.util.List;

public class Personnage {

    public static String[] direction = {"Nord", "Est", "Sud", "Ouest"};

    public static String tourner(int fois){
        return direction[fois];
    }
}
