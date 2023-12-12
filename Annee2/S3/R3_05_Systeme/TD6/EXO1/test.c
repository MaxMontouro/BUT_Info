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

void* thread_coiffeur(void*); // Ajout de void* pour respecter le prototype
int nombre_client();           // Retourne un nombre aléatoire entre 1 et 10
void* thread_client(void*);    // Ajout de void* pour respecter le prototype

int main()
{
    // Definition du nombre de sièges dispo
    printf("Aujourd'hui vous définirez le nombre de sièges dispo en salle d'attente : (veuillez entrer un nombre entre 1 et 10)\n(PS : si vous entrez un nombre supérieur à 10, il sera automatiquement ramené à 10) : ");
    int nb_sieges;
    scanf("%d", &nb_sieges);
    if (nb_sieges > 10)
    {
        nb_sieges = 10;
    }

    // DECLARATION DES THREADS
    pthread_attr_t attr_coiffeur; // Attributs des threads
    pthread_t id_thread_coiffeur; // Identifiant du thread coiffeur
    pthread_attr_init(&attr_coiffeur); // Initialisation des attributs des threads

    pthread_attr_t attr_client; // Attributs des threads
    pthread_t id_thread_client; // Identifiant du thread client
    pthread_attr_init(&attr_client); // Initialisation des attributs des threads

    // Boucle
    while (1)
    {
        if (rand() % 2 == 0)
        {
            printf("Le coiffeur est en train de dormir\n");
            sleep(1);
        }
        else
        {
            for (int i = rand() % 10 + 1; i > 0; i--)
            {
                pthread_create(&id_thread_coiffeur, &attr_coiffeur, thread_coiffeur, NULL);
                pthread_create(&id_thread_client, &attr_client, thread_client, &nb_sieges);
            }
        }
    }
    return 0;
}

void* thread_coiffeur(void*)
{
    int nb_client = nombre_client();
    for (int i = nb_client; i > 0; i--)
    {
        printf("Le client %d est en train de se faire coiffer\n", i);
        sleep(5);
        printf("Le client %d a fini de se faire coiffer\n", i);
        printf("Il reste donc %d clients à coiffer\n", i);
    }
    pthread_exit(NULL);
}

int nombre_client()
{
    return rand() % 10 + 1;
}

void* thread_client(void* arg)
{
    int* nb_sieges = (int*)arg; // Conversion de void* à int*
    int aleatoire = rand() % 10 + 1;
    if (sleep(aleatoire) == 0)
    {
        printf("Puis-je rentrer ?\n");
        if (*nb_sieges > 0)
        {
            printf("Un client est entré\n");
            (*nb_sieges)--;
        }
    }
    pthread_exit(NULL);
}