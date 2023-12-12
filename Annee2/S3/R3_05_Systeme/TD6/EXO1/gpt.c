#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

// Nombre maximum de clients
const int MAX_CLIENTS = 10;
// Nombre minimum de clients
const int MIN_CLIENTS = 1;

// Temps maximum d'attente pour la demande d'un client (entre 1 et 10 secondes)
const int TEMPS_MAX_ATTENTE_DEMANDE_CLIENT = 10;
// Temps maximum pour la coiffure (entre 1 et 10 secondes)
const int TEMPS_MAX_COIFFURE = 5;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

struct Client {
    int nombreSiegesDispo;
    int *tableauDeSiegesDispo; // Utilisation d'un pointeur pour un tableau dynamique
    int nbClient;
};

void *fonction_coiffeur(void *arg) {
    struct Client *client = (struct Client *)arg;
    printf("Le coiffeur est en train de dormir\n");
    sleep(1);
    printf("Le coiffeur se réveille\n");
    while (1) {
        for (int i = 0; i < client->nombreSiegesDispo; i++) {
            if (client->tableauDeSiegesDispo[i] != 0) {
                pthread_mutex_lock(&mutex);
                printf("Le coiffeur est en train de couper les cheveux d'un client %d\n", client->tableauDeSiegesDispo[i]);
                printf(" qui est assis sur la chaise %d\n", i + 1);
                pthread_mutex_unlock(&mutex);
                sleep(TEMPS_MAX_COIFFURE);
                pthread_mutex_lock(&mutex);
                client->tableauDeSiegesDispo[i] = 0;
                pthread_mutex_unlock(&mutex);
            }
        }
    }
    pthread_exit(NULL);
}

void *fonction_client(void *arg) {
    struct Client *client = (struct Client *)arg;
    pthread_t idThreadClient = pthread_self();
    
    for (int i = 0; i < client->nombreSiegesDispo; i++) {
        if (client->tableauDeSiegesDispo[i] == 0) {
            printf("Le client %lu s'assoit sur la chaise %d\n", idThreadClient, i + 1);
            printf("Le client %lu est en train de se faire coiffer\n", idThreadClient);
            pthread_mutex_lock(&mutex);
            client->tableauDeSiegesDispo[i] = idThreadClient;
            client->nbClient--;
            pthread_mutex_unlock(&mutex);
            printf("Le client %lu assis sur la chaise %d s'est fait couper les cheveux et est parti\n", idThreadClient, i + 1);
            return NULL;
        }
    }
    printf("Le client %lu n'a pas pu s'asseoir et est parti\n", idThreadClient);
    pthread_exit(NULL);;
}

int main(void) {
    srand(time(NULL));

    struct Client client;
    client.nombreSiegesDispo = rand() % 10 + 1;
    client.tableauDeSiegesDispo = malloc(client.nombreSiegesDispo * sizeof(int));
    client.nbClient = rand() % 10 + 1;//nombre de clients aléatoire entre 1 et 10

    //definition des threads
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_t idThreadCoiffeur;
    pthread_create(&idThreadCoiffeur, &attr, fonction_coiffeur, (void *)&client);

    //affichage des valeurs
    printf("Pour ce programme, le nombre de sièges est de %d et de %d clients\n", client.nombreSiegesDispo, client.nbClient);
    printf("Le temps de coupe est de %d secondes\n", TEMPS_MAX_COIFFURE);

    for (int i = 0; i < client.nombreSiegesDispo; i++) {
        client.tableauDeSiegesDispo[i] = 0;
    }

    while (1) {
        for (int i = 0; i < rand() % client.nbClient; i++) {
            pthread_t idThreadClient; // Identifiant du thread client
            pthread_create(&idThreadClient, &attr, fonction_client, (void *)&client);
            pthread_join(idThreadClient, NULL); // Attendre la fin du thread client
        }
        sleep(TEMPS_MAX_ATTENTE_DEMANDE_CLIENT);
    }

    printf("Il n'y a plus de client\n");
    printf("Le coiffeur est parti\n");
    free(client.tableauDeSiegesDispo);

    pthread_join(idThreadCoiffeur, NULL);
    pthread_mutex_destroy(&mutex);

    return 0;
}
