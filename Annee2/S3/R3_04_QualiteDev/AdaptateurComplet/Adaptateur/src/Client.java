public class Client {
    //CONSTRUCTEUR
    Client(){
    }
    public static void main(String[] args) {
        Disponible dispo = new Disponible();
        ICible cible = new Adaptateur(dispo);
        cible.operation();
    }
}
