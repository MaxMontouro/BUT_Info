package com.Maks.chiffresRomains;

public class ArabicRomanNumerals {
    public static String convert(int nombre){
        // Tableau des chiffres romains et des valeurs correspondantes
        int[] valeurs = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        String[] symboles = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

        StringBuilder resultat = new StringBuilder();

        // Boucle sur les valeurs et symboles
        for (int i = 0; i < valeurs.length; i++) {
            while (nombre >= valeurs[i]) {
                resultat.append(symboles[i]);
                nombre -= valeurs[i];
            }
        }

        return resultat.toString();
    }
}
