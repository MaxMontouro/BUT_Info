/**
    * @file main.c
    * @author MaxMontouro
    * @date 2021-10-13
    * @version 0.1
    * @note TP6 EXO1
    */

#include <stdlib.h> //: Gestion de la mémoire, conversions et fonctions systèmes
#include <string.h> //: Gestion de chaînes de caractères
#include <ctype.h> //: Manipulation de caractères
#include <stdio.h> //: Gestion des fichiers et des Entrées/Sorties en général
#include <unistd.h> //: Accès à l'API du système d'exploitation POSIX
#include <threads.h> //: Création/Gestion de threads
#include <ctype.h> //: Manipulation de caractères
#include <sys/wait.h> //: Gestion des processus
#include <errno.h> //: Gestion des erreurs
#include <pthread.h> //: Création/Gestion de threads
#include <signal.h> // Gestion des signaux
#include <time.h> //: Gestion du temps


void thread_coiffeur(); 
int nombre_client(); // retourne un nombre aléatoire entre 1 et 10

int main(){

    //DECLARATION DES THREADS
    pthread_attr_t attr; //: Attributs des threads
    pthread_t id_thread_coiffeur; //: Identifiant du thread coiffeur
    pthread_attr_init(&attr); //: Initialisation des attributs des threads

    //Definition du nombre de sièges dispo
    printf("Aujourd'hui vous définirez le nombre de sièges dispo en salle d'attente : (veuillez entrer un nombre entre 1 et 10)\n(PS : si vous entrez un nombre supérieur à 10, il sera automatiquement ramené à 10) : ");
    int nb_sieges;
    scanf("%d", &nb_sieges);
    if(nb_sieges > 10){
        nb_sieges = 10;
    }

    //Boucle
    while(1){
        if(rand()%2 == 0){
            printf("Le coiffeur est en train de dormir\n");
            sleep(1);
        }
        else{
        for int i = rand()%10+1; i > 0; i--{;
            pthread_create(&id_thread_coiffeur, &attr, thread_coiffeur, NULL);
            
            }
        }
    }
    return 0;
}

void thread_coiffeur(){
    int nb_client = nombre_client();
    for(int i = nb_client; i > 0; i--){
        printf("Le client %d est en train de se faire coiffer\n", i);
        sleep(5);
        printf("Le client %d a fini de se faire coiffer\n", i);
        printf("Il reste donc %d clients à coiffer\n", i);
    }
    pthread_exit(NULL);
}

int nombre_client(){
    return rand()%10+1;
}