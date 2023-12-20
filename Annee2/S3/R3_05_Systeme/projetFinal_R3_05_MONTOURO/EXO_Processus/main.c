/**
    * @brief Programme de gestion d'un salon de coiffure
    * @author MaxMontouro
    * @file main.c
    * @date 2021-10-13
    * @version 0.1
    * @note TP6 EXO2 avec les proccesus
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <time.h>

#define MAX_CLIENTS 10
#define MIN_CLIENTS 1
#define TEMPS_MAX_COIFFURE 5

int* tableauDeSiegesDispo; // Pointeur vers la mémoire partagée
int shmid; // Identificateur de la mémoire partagée

void fonction_coiffeur(int nombreSiegesDispo, int* nombreClient) {
    while (*nombreClient > 0) {
        for (int i = 0; i < nombreSiegesDispo; i++) {
            if (tableauDeSiegesDispo[i] != 0) {
                printf("Le coiffeur est en train de couper les cheveux d'un client %d\n", tableauDeSiegesDispo[i]);
                printf(" qui est assis sur la chaise %d\n", i + 1);
                sleep(TEMPS_MAX_COIFFURE);
                tableauDeSiegesDispo[i] = 0;
            }
        }
        sleep(1);
    }
    printf("Il n'y a plus de client\n");
}

void fonction_client(int nombreSiegesDispo, int* nombreClient) {
    pid_t pid;

    for (int i = 0; i < nombreSiegesDispo && *nombreClient > 0; i++) {
        if (tableauDeSiegesDispo[i] == 0) {
            pid = getpid();
            printf("\n");
            printf("Le client %d s'assoit sur la chaise %d\n", pid + i, i + 1);
            printf("Le client %d est en train de se faire coiffer\n", pid);
            tableauDeSiegesDispo[i] = pid + i;
            (*nombreClient)--;
            sleep(TEMPS_MAX_COIFFURE);
            printf("Le client %d s'est fait couper les cheveux et est parti\n", pid + i);
            printf("\n");
            tableauDeSiegesDispo[i] = 0;
            sleep(1);
        }
    }
    printf("\n");
    printf("Le client %d n'a pas pu s'asseoir et est parti\n", pid + *nombreClient);
}

int main(void) {
    srand(time(NULL));

    int nombreClient = rand() % (MAX_CLIENTS - MIN_CLIENTS + 1) + MIN_CLIENTS;
    int nombreSiegesDispo = rand() % (MAX_CLIENTS - MIN_CLIENTS + 1) + MIN_CLIENTS;

    // Affichage des valeurs définies par les deux rand
    printf("Pour ce programme, le nombre de sièges est de %d et de %d clients\n", nombreSiegesDispo, nombreClient);
    printf("Le temps de coupe est de %d secondes\n", TEMPS_MAX_COIFFURE);

    printf("Le coiffeur dort\n");
    sleep(1);
    printf("Le coiffeur se réveille\n");

    // Création de la mémoire partagée
    shmid = shmget(IPC_PRIVATE, sizeof(int) * nombreSiegesDispo, IPC_CREAT | 0666);
    if (shmid == -1) {
        perror("Erreur de création de la mémoire partagée");
        exit(1);
    }

    // Attachement de la mémoire partagée
    tableauDeSiegesDispo = (int*)shmat(shmid, NULL, 0);
    if (tableauDeSiegesDispo == (int*)-1) {
        perror("Erreur d'attachement de la mémoire partagée");
        exit(1);
    }

    for (int i = 0; i < nombreSiegesDispo; i++) {
        tableauDeSiegesDispo[i] = 0;
    }

    int valeur, status;
    valeur = fork();

    if (valeur == -1) {
        perror("Erreur de création du processus fils");
        exit(1);
    }


    switch (valeur) {
        case 0:
            fonction_client(nombreSiegesDispo, &nombreClient);
            break;
            exit(EXIT_SUCCESS);
        default:
            fonction_coiffeur(nombreSiegesDispo, &nombreClient);
            wait(&status);
            break;
            exit(EXIT_SUCCESS);
    }

    // Détachement de la mémoire partagée
    if (shmdt(tableauDeSiegesDispo) == -1) {
        perror("Erreur de détachement de la mémoire partagée");
        exit(1);
    }

    // Suppression de la mémoire partagée
    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        perror("Erreur de suppression de la mémoire partagée");
        exit(1);
    }

    // Fin du programme
    printf("Il n'y a plus de client\n");
    printf("Le coiffeur est parti\n");
    
    exit(EXIT_SUCCESS);
    return 0;
}
