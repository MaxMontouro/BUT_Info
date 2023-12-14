public class Adaptateur implements ICible{
    //ATTRIBUT
    protected IDisponible utilise;

    //ENCAPSULATION utilise

    public IDisponible getUtilise(){
        return this.utilise;
    }

    public void setUtilise(IDisponible unUtilise){
        this.utilise = unUtilise;
    }

    //CONSTRUCTEUR
    Adaptateur(IDisponible d){
        super();
        setUtilise(d);
    }

    //METHODE
    public void operation(){
        utilise.operationDisponible();
    }
}
