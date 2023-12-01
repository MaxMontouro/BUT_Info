public abstract class DecorateurPizza implements IPizza{
    //ATTRIBUT
    protected IPizza composantPizza;

    //CONSTRUCTEUR
    DecorateurPizza(IPizza unePizza){
        setComposantPizza(unePizza);
    }

    //METHODE ENCAPSULATION

    //public IPizza getComposantPizza(){ return this.composantPizza;}
    public void setComposantPizza(IPizza unePizza){ this.composantPizza = unePizza;}

    //METHODE SPE
    public abstract String toString();
}
