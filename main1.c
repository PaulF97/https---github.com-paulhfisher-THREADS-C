#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define N_Threads 15

/*
 * Exercice 1
 * Paul Fisher
 */

void * func_1(void *thread_id){
    int id = *((int *) thread_id);
    printf("Hello from thread %d\n", id);
    return NULL;
}

int main(){

    pthread_t thread_ID[N_Threads];

    for(int i = 0; i < N_Threads; i++){
        int code = pthread_create(& thread_ID[i], NULL, func_1, &i);

            if(code != 0){
                fprintf(stderr, "pthread_create failed!\n");
                return EXIT_FAILURE;
            }
       printf("thread creer\n");

    }
return EXIT_SUCCESS ;
}
