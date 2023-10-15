import java.io.PrintStream;
public class Ingredient {
    // ATTRIBUTS métier
    private String _libelle;
    private PlatCuisine _monPlat;

    // ATTRIBUTS
    private static Ingredient instance = null;

    // CONSTRUCTEUR
    public Ingredient(){
        this.setLibelle("");
    };
    public Ingredient(String unNom){
        setLibelle(unNom);
    };
    public Ingredient(Ingredient unIngredient){
        setLibelle(unIngredient.getLibelle());
    };

    // METHODE
    public static Ingredient get_instance(){
        if(instance == null){
            instance = new Ingredient();
        }
        return instance;
    }


    // METHODES métier
    public String getLibelle(){
        return _libelle;
    }
    public void setPlat(PlatCuisine monPlat){
        _monPlat = monPlat;
    }
    public PlatCuisine getPlat(){
        return (_monPlat);
    }
    public void setLibelle(String nouvLibelle){
        this._libelle = nouvLibelle;
    }

    public String toString() {
        String message;
        message = "_libelle (" + getLibelle() + ")";
        if(this.getLibelle() != null)
            message += "COMPOSE LE/LA (" + this.getPlat().getLibelle() + ")";
        return message;
    }

    //EQUAL: dis si il est égal à un ingrédient
    public boolean equals (Ingredient unIngredient){
        return(getLibelle()==unIngredient.getLibelle());
    }

    //METHODES SPECIFIQUES delier/lier platCuisner

    public void delierPlatCuisiner(){
        if(this.getPlat() != null ){
            this.getPlat().delierIngredient(this);
            this.setPlat(null);
        }
    }

    public void lierPlatCuisiner(PlatCuisine plat){
        this.delierPlatCuisiner();
        this.setPlat(plat);
        plat.ajouterIngredient(this);
    }


}
