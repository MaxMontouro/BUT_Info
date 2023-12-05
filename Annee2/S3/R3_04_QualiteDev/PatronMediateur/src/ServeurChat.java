import java.util.ArrayList;
import java.util.Iterator;

public class ServeurChat extends Mediateur{
    //ATTRIBUT
    String nomServeur;
    ArrayList<Utilisateur> lUtilisateur = new ArrayList<>();

    //CONSTRUCTEUR

    ServeurChat(String nom){
        this.nomServeur = nom;
    }

    ServeurChat(){
        super();
        this.nomServeur = " ";
    }

    //ENCAPSULTAION
    public String getlUtilisateur(){
        return lUtilisateur.toString();
    }

    public void setlUtilisateur(Utilisateur unUser){
        ajouterUtilisateur(unUser);
    }

    public boolean ajouterUtilisateur(Utilisateur unUser){
        return lUtilisateur.add(unUser);
    }
    public boolean supprimerUtilisateur(Utilisateur unUser){
        return lUtilisateur.remove(unUser);
    }

    public boolean estUtilisateur(Utilisateur unUser){
        return lUtilisateur.contains(unUser);
    }

    public String toString() {
        String message = "( ";
        if (!lUtilisateur.isEmpty())
            for (Iterator<Utilisateur> it = lUtilisateur.iterator(); it.hasNext(); ) {
                message += it.next().getNom() + " ";//accede au suivant
            }
        message += ")";
        return message;
    }

    public void diffuserMessageDe(String msg, Utilisateur user){
        for(Utilisateur oneUser : lUtilisateur){
            if(oneUser != user){
                oneUser.recevoirMessageDe(msg, user);
            }
        }
    }
}
