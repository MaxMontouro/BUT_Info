public class Client {
    //CONSTRUCTEUR
    Client(){
    }
    public static void main(String[] args) {
        IDisponible dispo = new Disponible();
        ICible cible = new Adaptateur(dispo);
        cible.operation();
    }
}
