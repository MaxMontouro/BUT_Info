/**
    * @brief Programme de gestion d'un salon de coiffure
    * @author MaxMontouro
    * @file main.c
    * @date 2021-10-13
    * @version 0.1
    * @note TP6 EXO1 avec les threads
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

const int MAX_CLIENTS = 10; // Nombre maximum de clients
const int MIN_CLIENTS = 1; // Nombre minimum de clients
const int TEMPS_MAX_ATTENTE_DEMANDE_CLIENT = 10; // Temps maximum d'attente pour la demande d'un client (entre 1 et 10 secondes)
const int TEMPS_MAX_COIFFURE = 5; // Temps maximum pour la coiffure (entre 1 et 10 secondes)

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER; // Initialisation du mutex

struct Client {
    int nombreSiegesDispo;
    int *tableauDeSiegesDispo;
    int nbClient;
};

void *fonction_coiffeur(void *arg) {
    struct Client *client = (struct Client *)arg; // Récupération des données de la structure
    printf("Le coiffeur est en train de dormir\n");
    sleep(1);
    printf("Le coiffeur se réveille\n");
    while (1) {
        pthread_mutex_lock(&mutex);
        for (int i = 0; i < client->nombreSiegesDispo; i++) {
            if (client->tableauDeSiegesDispo[i] != 0) {
                printf("Le coiffeur est en train de couper les cheveux d'un client %d\n", client->tableauDeSiegesDispo[i]);
                printf(" qui est assis sur la chaise %d\n", i + 1);
                sleep(TEMPS_MAX_COIFFURE);
                printf("Le client %d s'est fait couper les cheveux et est parti\n", client->tableauDeSiegesDispo[i]);
                client->tableauDeSiegesDispo[i] = 0;
            }
        }
        pthread_mutex_unlock(&mutex);
        sleep(1);
    }
    pthread_exit(NULL);
}

void *fonction_client(void *arg) {
    struct Client *client = (struct Client *)arg; // Récupération des données de la structure
    pthread_t idThreadClient = pthread_self(); // Id du thread client

    pthread_mutex_lock(&mutex);
    for (int i = 0; i < client->nombreSiegesDispo; i++) {
        if (client->tableauDeSiegesDispo[i] == 0) {
            printf("Le client %lu s'assoit sur la chaise %d\n", idThreadClient, i + 1);
            printf("Le client %lu est en train de se faire coiffer\n", idThreadClient);
            client->tableauDeSiegesDispo[i] = idThreadClient;
            client->nbClient--;
            pthread_mutex_unlock(&mutex);
            sleep(TEMPS_MAX_COIFFURE);
            pthread_mutex_lock(&mutex);
            printf("Le client %lu s'est fait couper les cheveux et est parti\n", idThreadClient);
            client->tableauDeSiegesDispo[i] = 0;
            pthread_mutex_unlock(&mutex);
            pthread_exit(NULL);
        }
    }
    printf("Le client %lu n'a pas pu s'asseoir et est parti\n", idThreadClient);
    pthread_mutex_unlock(&mutex);
    pthread_exit(NULL);
}

int main(void) {
    srand(time(NULL)); // Initialisation de rand

    struct Client client; // Déclaration de la structure
    client.nombreSiegesDispo = rand() % 10 + 1;
    client.tableauDeSiegesDispo = malloc(client.nombreSiegesDispo * sizeof(int));
    client.nbClient = rand() % 10 + 1;

    // Définition des threads
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_t idThreadCoiffeur;
    pthread_create(&idThreadCoiffeur, &attr, fonction_coiffeur, (void *)&client);

    // Affichage des valeurs défini par les deux rand
    printf("Pour ce programme, le nombre de sièges est de %d et de %d clients\n", client.nombreSiegesDispo, client.nbClient);
    printf("Le temps de coupe est de %d secondes\n", TEMPS_MAX_COIFFURE);

    // Initialisation du tableau des sièges à 0
    for (int i = 0; i < client.nombreSiegesDispo; i++) {
        client.tableauDeSiegesDispo[i] = 0;
    }

    //boucle principale du programme qui execute les threads clients
    while (client.nbClient > 0) {
        for (int i = 0; i < rand() % client.nbClient + 1; i++) {
            pthread_t idThreadClient;
            pthread_create(&idThreadClient, &attr, fonction_client, (void *)&client);
            // pthread_join(idThreadClient, NULL); // Retiré pour éviter le blocage du programme
        }
        sleep(TEMPS_MAX_ATTENTE_DEMANDE_CLIENT);
    }

    // Fin du programme
    printf("Il n'y a plus de client\n");
    printf("Le coiffeur est parti\n");
    free(client.tableauDeSiegesDispo); // Libération de la mémoire

    pthread_cancel(idThreadCoiffeur); // Annulation du thread coiffeur
    pthread_join(idThreadCoiffeur, NULL); // Attente de la fin du thread coiffeur
    pthread_mutex_destroy(&mutex); // Destruction du mutex

    return 0;
}
