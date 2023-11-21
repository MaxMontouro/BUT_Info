import java.util.ArrayList;

public abstract class Observable {
    //ATTRIBUT
    protected ArrayList<Observateur> mesObservateurs = new ArrayList<Observateur>();

    //METHODES SPECIFIQUES
    public boolean ajouterObservateur(Observateur unObservateur){return mesObservateurs.add(unObservateur);};
    public boolean supprimerObservateur(Observateur unObservateur){return mesObservateurs.remove(unObservateur);};
    public boolean existeObservateur(Observateur unObservateur){return mesObservateurs.contains(unObservateur);};


    protected void notifierObservateur(){
        for (Observateur obs: mesObservateurs){
            obs.reagir();
        }
    }
}
