public class Main{
    public static void main(String[]args){
        SingletonChefCuisinier leChefCuisinier;
        SingletonChefCuisinier leCuisinier;
        leChefCuisinier = SingletonChefCuisinier.get_instance();
        leChefCuisinier.setNom("Navarro");
        System.out.println(leChefCuisinier.getNom());

        leCuisinier = SingletonChefCuisinier.get_instance();
        System.out.println(leCuisinier.getNom());
    }
}