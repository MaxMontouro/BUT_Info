package com.Maks.Jeu;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class PersonnageTest {

    @Test
    public void le_test_devrait_retourner_Nord_avec_en_param_0(){

        //GIVEN
        int direction = 0;

        //WHEN

        String resultat = Personnage.tourner(direction);

        //THEN

        assertEquals(resultat, "Nord");
    }

    @Test
    public void le_test_devrait_retourner_la_direction_en_fonction_du_param(){

        //GIVEN
        int direction = 3; // Valeur à changer

        //WHEN

        String resultat = Personnage.tourner(direction);

        //THEN

        assertEquals(resultat, "Ouest");
    }

    @Test
    public void le_test_devrait_retourner_la_direction_en_fonction_du_switch_et_du_param(){

        //GIVEN
        int direction = 2;

        //WHEN

        String resultat = Personnage.tourner(direction);

        //THEN
        assertEquals(resultat, "Est");
    }
}