public class DecorateurAvecOlives extends DecorateurPizza{
    //CONSTRUCTEUR
    DecorateurAvecOlives(IPizza unePizza){
        super(unePizza);
    }

    //METHODE SPECIFIQUE
    public String toString(){
        return (composantPizza.toString() + "- Olives ");
    }
}
