public class ClasseXutilisantStrategie {
    //ATTRIBUT
    private IStrategie _uneStrategie;

    //CONSTRUCTOR
    public ClasseXutilisantStrategie(){};

    //METHODES
    public void operationMetier(){
        System.out.println("Commencement de l'opération métier");
        _uneStrategie.methodeDeStrategie();
        System.out.println("Terminaison de l'opération métier\n");
    };

    //GET&SET
    public void setLaStrategie(IStrategie uneInstatiationDeStrategie){

        _uneStrategie = uneInstatiationDeStrategie;
    }

    public IStrategie getStrategie(){
        return _uneStrategie;
    }

}
