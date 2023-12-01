public class ObservableMeteo extends Observable{
    //ATTRIBUT METIER
    private String date, libelle;
    private double temperature, pression;

    //CONSTRUCTEUR
    ObservableMeteo(String unNom){this.setLibelle(unNom);};
    //ENCAPSULATION
    public String getDate() {
        return this.date;
    }

    public double getPression() {
        return this.pression;
    }

    public double getTemperature() {
        return this.temperature;
    }

    public String getLibelle(){return this.libelle;}

    public void setLibelle(String unLib){this.libelle = unLib; notifierObservateur();}
    public void setPression(double pression) {
        this.pression = pression;
        notifierObservateur();
    }
    public void setTemperature(double temperature) {
        this.temperature = temperature;
        notifierObservateur();
    }
    public void setDate(String date) {
        this.date = date;
        notifierObservateur();
    }
}
