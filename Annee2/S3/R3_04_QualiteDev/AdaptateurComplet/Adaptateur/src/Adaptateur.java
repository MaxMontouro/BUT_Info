public class Adaptateur implements ICible{
    //ATTRIBUT
    protected Disponible utilise;

    //ENCAPSULATION utilise

    public Disponible getUtilise(){
        return this.utilise;
    }

    public void setUtilise(Disponible unUtilise){
        this.utilise = unUtilise;
    }

    //CONSTRUCTEUR
    Adaptateur(Disponible d){
        super();
        setUtilise(d);
    }

    //METHODE
    public void operation(){
        utilise.operationDisponible();
    }
}
