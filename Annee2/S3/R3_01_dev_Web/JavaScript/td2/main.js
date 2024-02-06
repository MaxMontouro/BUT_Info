console.log(document.forms['addForm'].getElementsByTagName("input")[1].value = "Submit");
console.log(document.forms['addForm'].nextElementSibling.value = "Submit");

document.getElementById("filter").placeholder = "Recherche un item dans la table...";



function masqueeEltNonOrdonnee(){
    let element = document.getElementById("items");
    element.style.display = "none"
}

//masqueeEltNonOrdonnee();

function masqueeEltAvecParametre(idParticulier){
    let element = document.getElementById(idParticulier);
    element.style.display = "none"
}


function CSS() {
    let e = document.getElementById("Items");
    e.style.fontSize = "12px";
    e.style.color = "blue";

    let e2 = document.getElementsByName("monFormulaire")[0];
    e2.className = "gros";
    console.warn(e2.className);
}

//On ajoute la balise style au code HTML
function affichage(){
    var element = document.querySelectorAll("#items, h2");
    for (it of element){
        it.classList.add("texteBlancFondNoir")
    }
}

affichage();

function doubleClick2(){
    let e1 = document.querySelector("li");
    let e2 = document.querySelector("li").nextElementSibling;
  
    e1.addEventListener("dblclick", (e) => {addClass2()});
    e2.addEventListener("dblclick", (e) => {addClass2()});
  
  }
  //doubleClick();
  
function doubleClick(){
    let e1 = document.querySelector("li");
    let e2 = document.querySelector("li").nextElementSibling;
  
  
    let elem = document.querySelectorAll("#items,h2")
  
  
    e1.addEventListener("dblclick", (e) => {
      e1.classList.toggle("texteNoirFondBlanc");})
  
    e2.addEventListener("dblclick", (e) => {
      e2.classList.toggle("texteNoirFondBlanc");})
  
}
doubleClick();

function supprimerElt(unElement){
    unElement.remove();
}

function anonyme(){
    let e1 = document.getElementById("items").children[0];
    let b1 = document.querySelector("#items, li, button").children[0];

    b1.addEventListener("click", (e) => {
        e1.remove();})

    let e2 = document.getElementById("items").children[1];
    let b2 = document.querySelector("#items, li, button").children[1];

    b1.addEventListener("click", (e) => {
        e1.remove();})
        
    b2.addEventListener("click", (e) => {
        e2.remove();})
    
    
}
//anonyme();

    function anonyme2(){
    let b1 = document.querySelectorAll(".btn.btn-danger.btn-sm.float-right");

    if (b1.length > 0) {
    // Parcourez tous les boutons et ajoutez un gestionnaire d'événements de clic à chacun
    b1.forEach(function(bouton) {
        bouton.addEventListener("click", (e)=> {
            // Supprimez le bouton lorsque le clic est détecté
            bouton.parentNode.removeChild(bouton);
        });
    });
}
}
anonyme2();

function ajouterEvent(){
    let element = document.querySelectorAll("ul");
    for (let index = 0; index < element.length; index++) {
        element.anonyme2();
    }
}

lesdonnees = 
[
    {
        "item": "Item 4",
        "article" : {
            "court" : "cafe soluble",
            "long" : "café lyophilisé (pack de 10 sachets)"
        },
        "qtstock" : 17,
        "prixht" : "3.20€"
    },
    {
        "item": "Item 5",
        "article" : {
            "court" : "fois gras",
            "long" : "fois gras de canard (au kilo)"
        },
        "qtstock" : 0,
        "prixht" : "33.0"
    },
    {
        "item": "Item 6",
        "article" : {
            "court" : "graines",
            "long" : "Muesli complet (paquet)"
        },
        "qtstock" : 12,
        "prixht" : "2.50€"
    }
]

/*function exploitation(){
    
}*/