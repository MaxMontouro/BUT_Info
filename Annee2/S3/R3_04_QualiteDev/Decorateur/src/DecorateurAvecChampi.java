public class DecorateurAvecChampi extends DecorateurPizza{
    //CONSTRUCTEUR
    DecorateurAvecChampi(IPizza unePizza){
        super(unePizza);
    }

    //METHODE SPE
    public String toString(){
        return (this.composantPizza.toString() + "- Champignons ");
    }
}
