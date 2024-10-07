package com.Maks.chiffresRomains;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class ArabicRomanNumeralsTest {

    @Test
    public void renvoie_le_nombre_entier_passer_en_param(){
        //GIVEN
        int nombre = 1;

        //WHEN

        String res = ArabicRomanNumerals.convert(nombre);

        //THEN
        assertEquals(nombre, Integer.parseInt(res));
    }

    @Test
    public void renvoie_le_nombre_en_chiffre_romain(){

        //GIVEN
        int nombre = 1987;

        //WHEN
        String res = ArabicRomanNumerals.convert(nombre);

        //THEN
        assertEquals("MCMLXXXVII", res);
    }
}