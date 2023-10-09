/**
 * Classe : Main
 * Objectif : Mettre en évidence les problèmes liés à la différence entre l'objet et son adresse
 * 
 * 1. Créer un pointeur c'est différent que de créer un objet 
 * 2. Cas de l'objet référencé par deux pointeurs
 * 3. Créer un objet à l'identique d'un objet modèle : constructeur par recopie
 * 
 * 4. Comparer deux pointeurs versus comparer deux objets
 *  4.a Comparer 2 pointeurs
 *  4.b Comparer 2 objets => la méthode boolean equals(objetModele)
 * 
 * 5. Paramètres des fonctions et méthodes : seule la valeur de la variable est transmise 
 *  5.a Paramètre "type primitif"
 *  	=> modifications de la variable sans effet au niveau appelant
 *  5.b Paramètre "pointeur"
 *  	=> modification de la référence sans effet au niveau appelant
 *      => modification de l'objet référencé avec effet au niveau appelant 
 * @version 2.0
 * @author Lopistéguy Philippe
 * @date jj/mm/aa
 */
public class Main {

/** 1.ATTRIBUTS              -non- **/
/** 2.CONSTRUCTEURS          -non- **/
/** 3.METHODES ENCAPSULATION -non- **/
/** 4.METHODES USUELLES      -non- **/

/** 5.METHODES SPECIFIQUES : modifierLeParametreDeTypePrimitifInt, modifierLeParametreAdresse, modifierObjetPointeParLeParametre **/

	static public void modifierLeParametreDeTypePrimitifInt (int entierRecu) {
		System.out.println ("... je reçois l'entier "+ entierRecu +" et l'augmente de 1");
		entierRecu++;  // incrémentation
		System.out.println ("... pour moi il vaut "+ entierRecu +" et la fonction se termine");
	}
	
	static public void modifierLeParametreAdresse (Ingredients ingredient) {
		System.out.println ("... je reçois l'adresse de l'ingredient "+ingredient.toString());
		Ingredients unNouveau;
		unNouveau = new Ingredients ("vin", 40); // Crée unNouveau ingredient
		System.out.println ("... je crée un nouvel ingredient "+ unNouveau.toString());
		ingredient = unNouveau;					 
		System.out.println ("... le paramètre reçu pointe sur ce nouvel ingrédient "+ingredient.toString()+" et la fonction se termine");
	}
	
	static public void modifierObjetPointeParLeParametre (Ingredients ingredient) {
		System.out.println ("... je reçois l'adresse de l'ingredient "+ingredient.toString());
		ingredient.set_quantite(0);
		System.out.println ("... je modifie la quantité "+ ingredient.toString()+" et la fonction se termine");
	}

/** 6.METHODE PRINCIPALE: main() **/
	public static void main(String[] args) {
		
		 /* 1. Créer un pointeur c'est différent que de créer un objet 
		 * - un pointeur est capable de stocker l'adresse d'un objet
		 * - un objet est crée par un 'new'
		 * - un 'new' retourne l'adresse de l'objet créé
		 * => on récupère l'adresse dans un pointeur
		*/
		System.out.println("\n1. Créer un pointeur c'est différent que de créer un objet");
		Ingredients ingredient10;	// On crée le pointeur ingredients10,
		// on crée l'objet <"lait",10>
		ingredient10 = new Ingredients("lait",10);// et le pointeur ingredient10 récupère l'adresse de l'objet <"lait",10>
		System.out.println("ingredient10 contient l'adresse de "+ingredient10.toString());

		/* 2. Cas de l'objet référencé par deux pointeurs
		 *  a. déclarer 2 pointeurs
		 *  b. créer un objet et garder son @ dans le 1er pointeur
		 *  c. copier cette @ dans le 2ème pointeur
		 *  d. afficher l'objet que pointeur le 1er et le 2ème pointeur
		 *  e. modifier l'objet via le 2eme pointeur & constater la modification
		 *  f. afficher l'objet pointé par chacun de ces 2 pointeurs
		 * => les modifications de l'objet via le 1er pointeur ont affecté les valeurs
		 *    de l'objet pointé par le 2è pointeur. Normal ! c'est le même objet
		 */
		System.out.println("\n2. Cas de l'objet référencé par deux pointeurs");
		Ingredients ingredient21;	// a. création d'un 1er pointeur ingredient21
		Ingredients ingredient22;	// a. création d'un 2eme pointeur ingredient22
		ingredient21 = new Ingredients("sel", 21);	// b. le 1er pointe sur new objet <"sel", 21>
		ingredient22 = ingredient21;	// c. copier l'@ de l'objet dans le 2ème pointeur
		ingredient21.afficher();	// d. affichage via 1er pointeur
		ingredient22.afficher();	// d. affichage via 2ème pointeur
		ingredient21.set_libelle("Sel");	// e. modifier l'objet via le 1er pointeur
		ingredient21.afficher();	// f. affichage via 1er pointeur
		ingredient22.afficher();	//    et 2ème pointeur
		
		 /* 3. Créer un objet à l'identique d'un objet modèle : constructeur par recopie
		 *   a. écrire un constructeur avec un objet modele en paramètre (cf. classe Ingredients)
		 *   b. créer un 1er objet référencé par un 1er pointeur
		 *   c. créer un 2eme objet (sur la base du 1er objet) référencé par un 2ème pointeur
		 *   d. constater que les 2 pointeurs se référent à des objets de même valeur
		 *   e. modifier le premier objet
		 *   f. constater que chaque poitneur se référe à des objets de valeurs différentes
		 * => Constructeur par recopie
		 */
		System.out.println("\n3. Créer un objet à l'identique d'un objet modèle : constructeur par recopie");
		// a. est déjà fait : soyez tranquilles...
		Ingredients ingredient31;	// b. crée le 1er pointeur    ingredient31
		ingredient31 = new Ingredients("milk", 31);	// b. le 1er pointeur prend l'@ d'un ouvel objet <"milk", 31>
		Ingredients ingredient32;	// c. crée le 2ème pointeur   ingredient32
		ingredient32 = new Ingredients(ingredient31);	// c. le 2ème pointeur prend l'@ du 2ème objet qui est construit
                                //    sur la base du 1er objet, cad construit par recopie
		ingredient31.afficher();	// d. affichage de ce que pointe    ingredient31
		ingredient32.afficher();	// d. affichage de ce que pointe    ingredient32
		ingredient31.set_quantite(35);	// e. modification de l'un des 2 objets
		ingredient31.afficher();	// f. affichage  de ce que pointe    ingredient31
		ingredient32.afficher();	// f. affichage  de ce que pointe    ingredient32
		
		/* 4. Comparer deux pointeurs versus comparer deux objets
		 *  4.a Commparer 2 pointeurs
		 *      a. créer un objet référencé par un pointeur
		 *      b. copier le pointeur dans un second pointeur
		        c. observer qu'ils sont égaux (ils référencent le même objet)
		 *  4.b Comparer 2 objets
		 *      a. créer et initialiser un premier objet référencé par un 1er pointeur
		 *      b. créer et initialiser (aux même valeurs) un second objet référencé par un 2ème pointeur
		 *      c. comparer les pointeurs et constater qu'ils sont différents alors que les 2 objets référencés sont identiques
		 * 	d. (c'est déjà fait) surcharger la méthode "static public boolean equals(objetModele)" (cf. classe Ingredients) de sorte
		 *         à ce que l'objet considéré compare ses attributs à ceux de l'objet modèle et retourne vrai en cas d'égalitéS
		 */
		System.out.println("\n4. Comparer deux pointeurs versus comparer deux objets");
		System.out.println("   4.a Comparer deux pointeurs : pointeurs égaux"); 
		Ingredients ingredient41 = new Ingredients("salt",41);	// a. créer un objet <"salt", 41> pointé par ingredient41
		Ingredients ingredient42 = ingredient41;	// b. copier le pointeur dans un second pointeur ingredient42
		ingredient42.afficher();
		ingredient41.afficher();// c. observer que ingredient41 et ingredien42 sont égaux

		System.out.println("\n   4.b Comparer deux objets => la méthode boolean equals(objetModele)");
		Ingredients ingredient43 = new Ingredients("vin", 49);	// a. créer un objet pointé par ingredient43 aux valeurs <"vin", 49>
		Ingredients ingredient44 = new Ingredients("vin", 49);	// b. créer un 2ème objet pointé par ingredient44 aux mêmes valeurs <"vin", 49>
		System.out.println(ingredient43);
		System.out.println(ingredient44);// c. différence d'adresse des objets, mais mêmes valeurs
		System.out.println(ingredient43.equals(ingredient44));	// d.valeurs des objets identiqueS : regarder le 'if' (cf. methode equals)
		
		 /* 5. Paramètres des fonctions et méthodes : c'est la valeur de la variable qui est transmise
		  *   5.a Paramètre "type primitif" => modifications de la variable sans effet au niveau appelant
		  */
		System.out.println("\n5. Paramètres des fonctions et méthodes : c'est la valeur de la variable qui est transmise");
		System.out.println("     5.a Paramètre type primitif => modifications de la variable sans effet au niveau appelant");
		int unEntier = 20;
		System.out.println ("La valeur de unEntier "+unEntier+" est transmise à la fonction"); // avant  20
		modifierLeParametreDeTypePrimitifInt(unEntier);	// appeler :    modifierLeParametreDeTypePrimitifInt (int);
		System.out.println ("La valeur de unEntier "+unEntier+" et est INCHANGE après la fonction"); // après 20 inchangé !!!!
		
		//  5.b Paramètre "pointeur" => modification de la référence sans effet au niveau appelant
		System.out.println("\n     5.b Paramètre pointeur => modification de la référence sans effet au niveau appelant");
		Ingredients ingredient00 = new Ingredients ("huile", 10);
		System.out.println ("La valeur de l'ingredient "+ingredient00.toString()+" est transmise à la fonction"); // avant <huile,10>
		modifierLeParametreAdresse(ingredient00);	// appeler :   modifierLeParametreAdresse (Ingredients);
		System.out.println ("La valeur de l'ingredient "+ingredient00.toString()+" après la fonction INCHANGE"); // après <huile,10> inchangé !!!!
		
		//  5.c Paramètre "pointeur" => modification de l'objet référencé avec effet au niveau appelant 
		System.out.println("\n     5.c Paramètre pointeur => modification de l'objet avec effet au niveau appelant");
		Ingredients ingredient11 = new Ingredients ("thé", 11);
		System.out.println ("La valeur de l'objet pointé "+ingredient11.toString()+" est transmise à la fonction"); // avant <thé,10>
		modifierObjetPointeParLeParametre(ingredient11);	// appeler : 	modifierObjetPointeParLeParametre (Ingredients);
		System.out.println ("La valeur de l'objet pointé "+ingredient11.toString()+" après la fonction C H A N G E"); // après <vin,40> inchangé !!!!
	}
}
