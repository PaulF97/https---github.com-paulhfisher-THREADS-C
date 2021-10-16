#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

/*
 * Ce programme permet de calculer le
 * factorielle d'un nombre après avoir saisie la valeur
 * à calculer
 * Paul Fisher
 */


/*
 * Saisie du nombre souhaité
 * return : valeur saisie
 */
void saisieFactorielle (voidarg){
    int nombre;
    printf("Bienvenue dans le premier thread...\n");
    printf("veuillez rentrez un nombre\n");
    scanf("%d", &nombre);
    pthread_exit((void*) nombre); // renvoie le nombre saisie
}

/*
 * calcul du factorielle
 * param : nombre rentré dans le premier thread
 */
void* calculFactorielle (void* arg){

    int fac = 1, nbre;
    nbre = (int)arg; // nbre prend la valeur de ce qu'on a saisie
    printf("Bienvenue dans le deuxieme thread ...\n ");
    for(int i = 1; i<= nbre; i++){
        fac = fac * i;
    }
    printf("le factorielle de %d est : %d ", nbre, fac);
}


int main()
{


    pthread_t saisie, calcul; // déclarations de variables de types thread

    void *thread_saisie; // retour du premier thread


    // Creation du premier thread et attente de la fin de son execution
    printf("Attente de la terminaison du Thread 1 ...... \n");

    if(pthread_create(&saisie, NULL, saisieFactorielle, NULL)){ // on rentre dans le premier thread
        perror("pthread_create thread_1");
        return EXIT_FAILURE;
    }


    if(pthread_join(saisie,&thread_saisie)){
        perror("pthread_join thread_1");
        return EXIT_FAILURE;
    }

    // Creation du deuxième thread et attente de la fin de son execution
    if(pthread_create(&calcul, NULL, calculFactorielle,thread_saisie)){ // on passe en param la valer rentrée
        perror("pthread_create thread_2");
        return EXIT_FAILURE;
    }

    if(pthread_join(calcul,NULL)){
        perror("pthread_join thread_1");
        return EXIT_FAILURE;
    }


    return 0;
}


