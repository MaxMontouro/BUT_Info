import java.util.HashSet;
import java.util.Set;

public abstract class  Composant {
    //ATTRIBUTS
    protected String _libelle = "";
    protected int _prix = 0;

    public Set<Composant> enfants = new HashSet<Composant>();
    //ONSTRUCTEUR
    public Composant(){
        this._libelle = "";
        this._prix = 0;
    }
    public Composant(int prix, String libelle){
        this._prix = prix;
        this._libelle = libelle;
    }
    //METHODES USUELLES get&set
    public String get_libelle(){
        return this._libelle;
    }

    public void set_libelle(String unLibelle){
        this._libelle = unLibelle;
    }

    public void set_prix(int unPrix){
        this._prix = unPrix;
    }
    //METHODES METIERS
    public abstract int getPrix();

    public abstract String toString(String message);

    //RELATIONS
    public boolean ajouterComposant(Composant unComposant){
        return false;
    };
    public boolean retirerComposant(Composant unComposant){return false;}

    public boolean jeSuisComposant(Composant unComposant){return false;}

}
