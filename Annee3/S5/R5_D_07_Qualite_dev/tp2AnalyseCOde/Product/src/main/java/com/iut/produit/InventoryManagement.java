package com.iut.produit;

public class InventoryManagement {
    public static void main(String[] args) {
        // Création de produits
        AbstractProduct laptop = new ElectronicProduct("Laptop", 800.0, "HP");
        AbstractProduct smartphone = new ElectronicProduct("Smartphone", 500.0, "Samsung");

        // Création d'un panier d'achat
        ShoppingCart cart = new ShoppingCart();
        cart.addItem(laptop);
        cart.addItem(smartphone);

        // Calcul du total du panier
        double totalPrice = cart.calculateTotalPrice();
        System.out.println("Total du panier : $" + totalPrice);
    }
}

