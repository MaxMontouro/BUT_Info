package com.Maks.FizzBuzz;

import org.junit.jupiter.api.Test;
import org.junit.jupiter.params.ParameterizedTest;
import org.junit.jupiter.params.provider.CsvSource;

import static org.junit.jupiter.api.Assertions.*;

class FizzBuzzTest {

    @Test
    void fizzBuzz_de_1_devrait_retourner_1(){
        //GIVEN
        int nombre = 1;

        //WHEN

        String res = FizzBuzz.de(nombre);
        //THEN

        assertEquals("1", res);
    }

    @ParameterizedTest
    @CsvSource({
            "1, 1",
            "2, 2",
            "3, Fizz"
    })

    void fizzBuzz_de_3_devrait_retourner_Fizz(int nb, String unNombre){
        //GIVEN

        //WHEN
        String res = FizzBuzz.de(nb);

        //THEN
        assertEquals(unNombre, res);
    }
}