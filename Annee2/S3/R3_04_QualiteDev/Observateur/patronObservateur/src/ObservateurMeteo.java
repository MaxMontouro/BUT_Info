public class ObservateurMeteo extends Observateur{
    //ATTRIBUT
    ObservableMeteo observable;
    private String lDate, libelle;
    private double lTemperature, lPression;

    //CONSTRUCTEUR
    ObservateurMeteo(String unNom){this.libelle = unNom;};
    //ENCAPSULATION
    public String getlDate() {
        return lDate;
    }

    public double getlPression() {
        return lPression;
    }

    public double getlTemperature() {
        return lTemperature;
    }

    public void setlDate(String lDate) {
        this.lDate = lDate;
    }

    public void setlPression(double lPression) {
        this.lPression = lPression;
    }

    public void setlTemperature(double lTemperature) {
        this.lTemperature = lTemperature;
    }
    public void setObservable(ObservableMeteo unObservable){
        this.setlDate(unObservable.getDate());
        this.setlPression(unObservable.getPression());
        this.setlTemperature(unObservable.getTemperature());
    }
    public String getLibelleObservateur(){return this.libelle;}
    @Override
    public void reagir() {
        String date = observable.getDate();
        double temp = observable.getTemperature();
        double pression = observable.getPression();

        this.setlDate(date);
        this.setlPression(pression);
        this.setlTemperature(temp);
    }
}

