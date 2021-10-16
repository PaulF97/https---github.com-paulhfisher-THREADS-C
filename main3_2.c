#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

/*
 * Ce programme est une amélioration de la version précédente
 * Dans l'affichage, le numéro du thread sera indiqué
 */

void* threadExecute (void* arg){

    int nbreThread, i = 1;
    nbreThread = (int)arg; // nbre prend la valeur saisie dans le main
    do{
        printf("Vous etes les bienvenus.e.s dans le THREAD %d \n", i);
        i++;
    } while(i<=nbreThread);
    printf("fin de l'attente.. \n");

}

int main()
{

    // variable
    int nbre;

    // saisie du nombre de thread souhaité
    printf("cb de thread voulez vous lancer : ");
    scanf("%d", &nbre);

    pthread_t m_thread[nbre]; // tableau de thread

    // processus d'éxcécution
    if(pthread_create(&m_thread[nbre], NULL, threadExecute,nbre)){ // on passe en param la valer rentrée
       perror("pthread_create thread_1");
       return EXIT_FAILURE;
    }

    if(pthread_join(m_thread[nbre],NULL)){
       perror("pthread_join thread_1");
       return EXIT_FAILURE;
    }

   return 0;
}


