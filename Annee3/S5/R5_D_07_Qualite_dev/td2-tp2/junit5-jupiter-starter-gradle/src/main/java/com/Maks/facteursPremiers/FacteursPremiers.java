package com.Maks.facteursPremiers;

import java.util.ArrayList;
import java.util.List;

public class FacteursPremiers {

    public static List<Integer> generate(int nombre) {
        List<Integer> facteurs = new ArrayList<>();

        // On commence par diviser par 2
        while (nombre % 2 == 0) {
            facteurs.add(2);
            nombre /= 2;
        }

        // Puis on teste les nombres impairs à partir de 3
        for (int i = 3; i <= Math.sqrt(nombre); i += 2) {
            while (nombre % i == 0) {
                facteurs.add(i);
                nombre /= i;
            }
        }

        // Si le nombre restant est supérieur à 2, c'est un facteur premier
        if (nombre > 2) {
            facteurs.add(nombre);
        }

        return facteurs;
    }

    public static void main(String[] args) {
        int nombre = 56;  // Exemple : 56 = 2^3 * 7
        List<Integer> facteurs = generate(nombre);
        System.out.println("Décomposition en facteurs premiers de " + nombre + " : " + facteurs);
    }
}
