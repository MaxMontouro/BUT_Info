public class TesterStrategieTheorie {
    public static void  main(String[] args){
        ClasseXutilisantStrategie objetX;
        objetX = new ClasseXutilisantStrategie();

        IStrategie uneStrategie;

        uneStrategie = new StrategieConcrete1();
        objetX.setLaStrategie(uneStrategie);
        objetX.operationMetier();

        uneStrategie = new StrategieConcrete2();
        objetX.setLaStrategie(uneStrategie);
        objetX.operationMetier();
    }
}
