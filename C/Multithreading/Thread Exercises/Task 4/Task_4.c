#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void* thread(void* arg){
    for(int i = 0; i < 5; i++){
        printf("Thread %d: %d\n", arg, i+1);
    }
    return NULL;
}

int main(){

    pthread_t thread1,thread2;

    int a = 1;
    int b = 2;

    pthread_create(&thread1,NULL,thread,(void *) a);
    pthread_create(&thread2,NULL,thread,(void *) b);

    pthread_join(thread1,NULL);
    pthread_join(thread2,NULL);

    printf("program finished!");
    fflush(stdout);
    return 0;
}