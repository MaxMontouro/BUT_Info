#include <stdlib.h> // Gestion de la mémoire, conversions et fonctions systèmes
#include <string.h> // Gestion de chaînes de caractères
#include <ctype.h>   // Manipulation de caractères
#include <stdio.h>   // Gestion des fichiers et des Entrées/Sorties en général
#include <unistd.h>  // Accès à l'API du système d'exploitation POSIX
#include <threads.h> // Création/Gestion de threads
#include <sys/wait.h> // Gestion des processus
#include <errno.h>    // Gestion des erreurs
#include <pthread.h>  // Création/Gestion de threads
#include <signal.h>   // Gestion des signaux
#include <time.h>     // Gestion du temps

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER; //initialisation du mutex


void fonction_coiffeur(int nb_sieges){
    printf("Le coiffeur est en train de couper les cheveux d'un client\n");
    sleep(5);
    pthread_create(&id_thread_client, &attr_client, (void *)fonction_client, NULL);
    pthread_mutex_lock(&mutex); //verrouillage du mutex
    nb_sieges++;
    pthread_mutex_unlock(&mutex); //déverrouillage du mutex
    printf("Le coiffeur a fini de couper les cheveux d'un client\n");
}

void fonction_client(int nb_sieges, int nb_client){
    if(nb_client > 0){
        if(nb_sieges > 0){
            printf("Le client est en train de se faire coiffer\n");
            sleep(5);
            pthread_mutex_lock(&mutex); //verrouillage du mutex
            nb_client--;
            pthread_mutex_unlock(&mutex); //déverrouillage du mutex
            printf("Le client a fini de se faire coiffer\n");
        }
        else{
            printf("Il n'y a plus de place en salle d'attente\n");
        }
    }
}

int main()
{
    //definition du nombre de sièges et de clients
    int nb_sieges = rand()%10+1; //nombre de sièges aléatoire entre 1 et 10
    int nb_client = rand()%10+1; //nombre de clients aléatoire entre 1 et 10

    //definition des threads
    pthread_attr_t attr_coiffeur; // Attributs des threads
    pthread_attr_t attr_client; // Attributs des threads
    pthread_t id_thread_coiffeur; // Identifiant du thread coiffeur
    pthread_t id_thread_client; // Identifiant du thread client
    pthread_attr_init(&attr_coiffeur); // Initialisation des attributs des threads
    pthread_attr_init(&attr_client); // Initialisation des attributs des threads

    while(1){
        if(rand()%2 == 0){
            printf("Le coiffeur est en train de dormir\n");
            sleep(1);
        }
        else{
            printf("Le coiffeur se réveille\n");
            pthread_create(&id_thread_coiffeur, &attr_coiffeur, (void *)fonction_coiffeur, NULL);
            pthread_join(id_thread_coiffeur, NULL);
            break;
        }
    }
    printf("Il n'y a plus de client\n");

    pthread_mutex_unlock(&mutex); //déverrouillage du mutex
    pthread_mutex_destroy(&mutex); //destruction du mutex
    return 0;
}