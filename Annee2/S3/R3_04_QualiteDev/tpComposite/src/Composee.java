import java.beans.PropertyEditorSupport;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.Set;

public class Composee extends Composant{

    //METHODES METIERS
    public int getPrix(){
        int total = this._prix;
        for(Composant e: enfants){
            total += e.getPrix();
        }
        return total;
    }

    public String toString(String message){
        String resultat = message +"Le composant a pour libelle : " + this.get_libelle() + " et pour prix : " + this.getPrix();
        for(Composant unComposant: enfants){
            message += unComposant.toString(message + "...");
        }
        return message;
    }

    public Composee(String libelle, int prix){super(prix, libelle);}
    public Composee(){super();}

}
