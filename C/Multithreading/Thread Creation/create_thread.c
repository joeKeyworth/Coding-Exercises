#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* myThread(void* arg){
    printf("Thread created!\n");
    return NULL;
}

int main(){
    pthread_t thread;
    pthread_create(&thread,NULL,myThread,NULL);
    pthread_join(thread,NULL);
    printf("Success!\n");
    fflush(stdout);
    return 0;
}