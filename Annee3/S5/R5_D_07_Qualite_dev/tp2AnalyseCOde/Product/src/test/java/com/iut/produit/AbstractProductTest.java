package com.iut.produit;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.assertEquals;

public class AbstractProductTest {

    @Test
    public void testGetCost() {
        AbstractProduct product = new ConcreteProduct("Test Product", 50.0);
        assertEquals(50.0, product.getCost(), 0.001); // Utilisation de 0.001 comme marge d'erreur pour les doubles
    }


}
