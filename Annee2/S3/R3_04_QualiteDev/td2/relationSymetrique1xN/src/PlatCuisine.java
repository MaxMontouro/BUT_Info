import java.util.ArrayList;
import java.util.Iterator;

public class PlatCuisine {
    //ATTRIBUT
    String _libelle;
    ArrayList<Ingredient> _mesIngredients = new ArrayList<>();

    //CONSTRUCTEUR
    public PlatCuisine(){ this.setLibelle("");};
    public PlatCuisine(String unLibelle){
        this.setLibelle(unLibelle);
    };

    // METHODES métier
    public String getLibelle(){
        return _libelle;
    }
    public void setLibelle(String nouvLibelle){
        this._libelle = nouvLibelle;
    }
    public ArrayList<Ingredient> getIngredient(){
        return _mesIngredients;
    }
    public void setIngredient(ArrayList<Ingredient> nouvIngredient){
        this._mesIngredients = nouvIngredient;
    }

    //METHODES USUELLES toString1,2,3
    // toString1: parcours de ArrayList avec un acces direct aux elements
    //acces avec i du type int
    public String toString(){
            String message;
            message = "_libelle (" + getLibelle() + ")";
            if(! getIngredient().isEmpty())
                for (int i=0;i<_mesIngredients.size(); i++){
                    message += _mesIngredients.get(i).getLibelle()+" ";
                }
            message += ")";
            return message;
    }
    //toString2: parcours sequentiel de l'ensemble des elts de ArrayList
    //acces avec ingredient de type Ingredient
    public String toString2(){
        String message;
        message = "_libelle (" + getLibelle() + ")";
        if(! getIngredient().isEmpty())
            for (Ingredient ingredient: getIngredient()){
                message += ingredient.getLibelle()+" ";//accede au suivant
            }
        message += ")";
        return message;
    }
    //toString3: parcours de ArrayList avec un iterateur
    // acces avec it de type Iterator<Ingredient>
    public String toString3(){
        String message;
        message = "_libelle (" + getLibelle() + ")";
        if(! getIngredient().isEmpty())
            for (Iterator<Ingredient> it= getIngredient().iterator(); it.hasNext();){
                message += it.next().getLibelle()+" ";//accede au suivant
            }
        message += ")";
        return message;
    }

    public boolean equals(PlatCuisine plat) {
        boolean res;
        res = (getLibelle() == plat.getLibelle() && getIngredient() == plat.getIngredient());
        return  res;
    }
    public boolean existeIngredient(Ingredient ingredient){
        return (getIngredient().contains(ingredient));
    }
    public boolean ajouterIngredient(Ingredient ingredient){
        boolean ajouter;
        if(ajouter = (!existeIngredient(ingredient))){
            _mesIngredients.add(ingredient);
            ajouter = true;}
        else {ajouter = false;}
        return ajouter;

    }
    public boolean lierIngredient(Ingredient ingredient){
        boolean lier;
        if(! existeIngredient(ingredient)){
            ajouterIngredient(ingredient);
            ingredient.delierPlatCuisiner();
            ingredient.setPlat(this);
            lier = true;
        }
        else {lier = false;}
        return lier;
    }

    public boolean retirerIngredient(Ingredient ingredient){
        boolean retirer;
        if(retirer = existeIngredient(ingredient)){
            _mesIngredients.remove(ingredient);
        }
        return retirer;
    }

    public boolean delierIngredient(Ingredient ingredient){
        boolean delier;
        if(delier = retirerIngredient(ingredient)){
            ingredient.setPlat(null);
        }
        return delier;
    }
}
