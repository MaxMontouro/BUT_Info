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