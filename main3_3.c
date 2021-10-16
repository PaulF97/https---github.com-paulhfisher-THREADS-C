#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>




/*
 * Ce programme permet d'effectuer 1000 additions à la fois
 * en utilisant un thread.
 * Paul Fisher
 */


int compteur = 0; // variable globale

/*
 * Calcul de l'addition
 */
void * addition(void*arg){

    int incre = 1, nbreOperation;
    nbreOperation = (int)arg; // nbre prend la valeur saisie dans le main

    for(int i = 0; i<=nbreOperation; i++){
        printf("addition numero %d ", i);
        compteur = incre + i;
        printf("valeur nouvelle de 'compteur' %d\n", compteur);
    }
}


int main()
{
    // variables
    int nbreAddition = 1000;
    pthread_t threadAdd;

    // processus d'éxcécution
    if(pthread_create(&threadAdd, NULL, addition,nbreAddition)){ // on passe en param le nombre d'addition souhaité
       perror("pthread_create thread_1");
       return EXIT_FAILURE;
    }

    if(pthread_join(threadAdd,NULL)){
       perror("pthread_join thread_1");
       return EXIT_FAILURE;
    }
    return 0;
}
