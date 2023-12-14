import javax.print.attribute.standard.Media;

public class Main {
    public static void main(String[] args) {

        Mediateur unServeurChat = new ServeurChat();
        Utilisateur user1, user2, user3;
        user1 = new Utilisateur(unServeurChat, "Jean");
        user2 = new Utilisateur(unServeurChat, "Pascal");
        user3 = new Utilisateur(unServeurChat, "Michel");

        ((ServeurChat) unServeurChat).ajouterUtilisateur(user1);
        ((ServeurChat) unServeurChat).ajouterUtilisateur(user2);
        ((ServeurChat) unServeurChat).ajouterUtilisateur(user3);

        ((ServeurChat) unServeurChat).diffuserMessageDe(("Je suis " + user1.getNom() + " et je suis présent"), user1);
        ((ServeurChat) unServeurChat).diffuserMessageDe(("Je suis " + user1.getNom() + " et je suis présent"), user2);
    }
}