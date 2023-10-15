public class SingletonChefCuisinier {
    //CONSTRUCTEUR
    private static SingletonChefCuisinier instance = null;
    private SingletonChefCuisinier(){};
    public static SingletonChefCuisinier get_instance(){
        if(instance == null){
            instance = new SingletonChefCuisinier();
        }
        return instance;
    }
    //DECLARATIONS DES ATTRIBUTS
    private String _nom;
    private String _prenom;
    public void setNom(String nouveauNom){
        this._nom = nouveauNom;
    }
    public String getNom(){
        return _nom;
    }
    public void setPrenom(String nouveauPrenom){
        this._prenom = nouveauPrenom;
    }
    public String getPrenom(){
        return _prenom;
    }
}
