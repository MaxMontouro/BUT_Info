package com.iut.produit;

class ElectronicProduct extends AbstractProduct {
    private String Elbrand;

    protected ElectronicProduct(String name, double cost, String brand) {
        super(name, cost);
        this.Elbrand = brand;
    }

    public String getBrand() {
        return Elbrand;
    }

    @Override
    public double CalculatePrice() {
        // Complexité cyclomatique élevée (calcul compliqué)
        double price = getCost() * 2.0;
        for (int i = 0; i < 100; i++) {
            price += i;
        }
        return price;
    }
}
