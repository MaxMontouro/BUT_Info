public class Simple extends Composant {
    public int getPrix(){
        return _prix;
    }

    public String toString(String message){
        String resultat = message + ("L'objet a pour libelle : " + this.get_libelle() + "et pour prix : " + this.getPrix());
        return resultat;
    }

    public Simple(){super();}

    public Simple(String libelle, int prix){super(prix, libelle);}

}
