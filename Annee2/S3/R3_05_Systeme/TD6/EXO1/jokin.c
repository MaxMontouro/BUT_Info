#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

struct Client{
    int nombreSiegesDispo;
    int tableauDeSiegesDispo[];
};

//definition du nombre de clients
const int MAX_CLIENTS = 10; //nombre maximum de clients
const int MIN_CLIENTS = 1; //nombre minimum de clients

//definition des temps
const int TEMPS_MAX_ATTENTE_DEMANDE_CLIENT = 10; //temps maximum que met le client pour demander une coupe (entre 1 et 10 secondes)
const int TEMPS_MAX_COIFFURE = 5; //temps maximum que met le coiffeur pour coiffer quelqu'un (entre 1 et 10 secondes)


pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER; //initialisation du mutex

void *fonction_coiffeur(void *arg){
    struct Client *client = (struct Client*)arg; //recuperation des données de la structure
    printf("Le coiffeur est en train de dormir\n");
    int cpt = 0;
    sleep(1);
    printf("Le coiffeur se réveille\n");
    while(1){
        for(int i = 0; i < client->nombreSiegesDispo; i++){
            if(client->tableauDeSiegesDispo[i] != 0){ //verification si un client est assis sur une chaise
                pthread_mutex_lock(&mutex); //verrouillage du mutex
                printf("Le coiffeur est en train de couper les cheveux d'un client %d\n", client->tableauDeSiegesDispo[i]);
                sleep(TEMPS_MAX_COIFFURE);
                printf("Le coiffeur a fini de couper les cheveux d'un client %d\n", client->tableauDeSiegesDispo[i]);
                client->tableauDeSiegesDispo[i] = 0; //le client se lève de la chaise
                pthread_mutex_unlock(&mutex); //déverrouillage du mutex
            }
        }
        for(int i = 0; i < client->nombreSiegesDispo; i++){
            if(client->tableauDeSiegesDispo[i] == 0){ //verification si un siege est vide
                cpt++;
            }
        }
        if(cpt == client->nombreSiegesDispo){ //si tous les sieges sont vides
            break;
        }
    }
    return NULL;
}

void *fonction_client(void *arg){
    struct Client *client = (struct Client*)arg; //recuperation des données de la structure
    pthread_t idThreadClient = pthread_self(); // id du thread client
    printf("Le client %lu est en train de se faire coiffer\n", idThreadClient);

    //parcours du tableau pour verifier si un siege est disponible, si oui le client s'assoie
    for(int i=0; i< client->nombreSiegesDispo; i++){
        if(client->tableauDeSiegesDispo[i] == 0){ // si un siege est vide
            printf("Le client %lu s'assoit sur la chaise %d\n", idThreadClient, client->tableauDeSiegesDispo[i]);
            pthread_mutex_lock(&mutex); //verrouillage du mutex
            client->tableauDeSiegesDispo[i] = idThreadClient; //le client s'assoie sur la chaise
            pthread_mutex_unlock(&mutex); //déverrouillage du mutex
            printf("Le client %lu assis sur la chaise %d s est fait coupé les cheuveux et est parti\n", idThreadClient, i + 1);
            return NULL;
        }
    }  
    printf("Le client %lu n'a pas pu s'asseoir, et est parti\n", idThreadClient);
    return NULL;
}



int main(void){

    srand(time(NULL)); //initialisation de rand 

    //definition des variables
    int nbSieges = rand()%10+1; //nombre maximum de sièges
    int nbCLients = rand()%10+1; // definition d'un nombre aleatoire entre 1 et 10 pour le nombre de clients
    int tempsAttenteDemandeClient = rand()%10+1; //temps que met le client pour demander une coupe (entre 1 et 10 secondes)

    //creation de la structure du tableau
    struct Client client;
    client.nombreSiegesDispo = nbSieges;//nombre de sieges
    client.tableauDeSiegesDispo[nbSieges];//tableau de sieges
    

    //affichage des valeurs
    printf("Pour ce programme, le nombre de sièges est de %d et de %d clients\n", nbSieges, nbCLients);
    printf("Le temps de coupe est de %d secondes\n", TEMPS_MAX_COIFFURE);

    //definition des threads
    pthread_attr_t attr; // Attributs des threads
    pthread_attr_init(&attr); // Initialisation des attributs des threads

    //creation du thread coiffeur
    pthread_t idThreadCoiffeur; // thread coiffeur
    pthread_create(&idThreadCoiffeur, &attr, fonction_coiffeur, (void*)&client);//création du thread coiffeur

    //initialisation du tableau des sièges
    for(int i = 0; i < client.nombreSiegesDispo; i++){
        client.tableauDeSiegesDispo[i] = 0;
    }

    //boucle principale du programme qui execute les threads clients
    while(1){
        for(int i = 0; i < rand()%(MAX_CLIENTS - MIN_CLIENTS) + MIN_CLIENTS; i++){
            pthread_t idThreadClient; // thread client
            pthread_create(&idThreadClient, &attr, fonction_client, (void*)&client);//création du thread client
        }
        sleep(tempsAttenteDemandeClient);
    }
    printf("Il n'y a plus de client\n");
    printf("Le coiffeur est parti\n");
    free(client.tableauDeSiegesDispo);//liberation de la memoire
    //attente de la fin du thread coiffeur
    pthread_join(idThreadCoiffeur, NULL);
    return EXIT_SUCCESS;

}