public class Main {
    public static void main(String[] args) {
        //Création d'une pizza
        IPizza unePizza = new Pizza();

        System.out.println(unePizza.toString()); //affichage de la pizza de base

        //transformation de la pizza
        unePizza = new DecorateurAvecOlives(unePizza);
        System.out.println(unePizza.toString());

        unePizza = new DecorateurAvecChampi(unePizza);
        System.out.println(unePizza.toString());
    }
}