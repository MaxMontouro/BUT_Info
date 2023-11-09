class Mot{
    constructor(taille, description){
        this.taille = taille; // taille du mot (str)
        this.description = description; // descrpition du mot (str)
    };

    getTaille(){
        return this.taille;
    }
    
    getDescrpition(){
        return this.description;
    }

    setTaille(uneTaille){
        this.taille = uneTaille;
    }

    setDescription(uneDescrpition){
        this.description = uneDescrpition;
    }

    tailleMot(unMot)// affiche la longueur d'un mot
    {
         console.log(unMot.lenght()); 
    }
}

class Utilisateur{
    constructor(nom = "", prenom = "", age = 0)//un utilisateur est defini par un nom, prenom et son age
    {
        this.nom = nom;
        this.prenom = prenom;
        this.age = age;
    }

    getNom(){
        return this.nom;
    }
    
    getPrenom(){
        return this.prenom;
    }

    getAge(){
        return this.age;
    }

    setPrenom(unPrenom){
        this.prenom = unPrenom;
    }

    setNom(unNom){
        this.nom = unNom;
    }

    setAge(unAge){
        this.age = unAge;
    }

    toString(){
        console.log('Je suis ' + this.getNom() + " " + this.getPrenom() + " et j'ai : " + this.getAge() + " ans");
    }
}

