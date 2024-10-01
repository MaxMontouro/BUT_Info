package com.Maks.facteursPremiers;

import org.junit.jupiter.api.Test;

import java.util.ArrayList;
import java.util.List;

import static org.junit.jupiter.api.Assertions.*;


class FacteursPremiersTest {

    @Test
    public void generate_devrait_retourner_la_decomposition_du_nombre(){
        //GIVEN
        int exemple = 6;
        List<Integer> listeEntiers = new ArrayList<>();
        listeEntiers.add(2);
        listeEntiers.add(3);

        //WHEN
        List<Integer> array = new ArrayList();
        array = FacteursPremiers.generate(exemple);

        //THEN
        assertEquals(array, listeEntiers);
    };
}