public class Utilisateur extends Acteur{
    //ATTRIBUT
    private String _nom;

    //CONSTRUCTEUR
    Utilisateur(Mediateur serveur, String unNom){
        super(serveur);
        this._nom = unNom;
    }

    //ENCAPSULTAION
    public void setNom(String nom){
        this._nom = nom;
    }
    public String getNom(){
        return this._nom;
    }

    //METHODES SPE
    public void recevoirMessageDe(String msg, Utilisateur lUtilisateur){
        System.out.println("L'utilisateur : " + lUtilisateur._nom + " a dit " + msg + " et l'utilisateur " + this._nom + " l'a recu");
    };
}
