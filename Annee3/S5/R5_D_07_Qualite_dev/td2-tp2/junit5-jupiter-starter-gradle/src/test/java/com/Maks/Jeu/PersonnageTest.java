package com.Maks.Jeu;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class PersonnageTest {

    @Test
    public void le_test_devrait_retourner_la_direction_de_base(){

        //GIVEN
        int direction = 1;

        //WHEN

        String resultat = Personnage.tourner(direction);

        //THEN

        assertEquals(resultat, "Nord");
    }
}