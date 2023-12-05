import javax.print.attribute.standard.Media;

public class Acteur{
    protected Mediateur monMediateur;

    public void setMonMediateur(Mediateur unMediateur){
        this.monMediateur = unMediateur;
    }

    public Mediateur getMonMediateur(){
        return monMediateur;
    }

    //CONSTRCUTEUR
    Acteur(Mediateur unMediateur){
        this.setMonMediateur(unMediateur);
    };
}
