package com.iut.produit;
import java.util.*;
class ShoppingCart {
    private List<AbstractProduct> Items = new ArrayList<>();
    private  double Tprice;
    public void addItem(AbstractProduct item) {
        Items.add(item);
    }

    public double calculateTotalPrice() {
        double TotalPrice = 0;
        for (AbstractProduct item : Items) {
            TotalPrice += item.calculatePrice();
        }
        return TotalPrice;
    }
}
