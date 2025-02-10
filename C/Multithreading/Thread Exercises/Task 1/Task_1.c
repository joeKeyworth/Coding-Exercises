#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void* thread1Func(void* arg){
    printf("Thread 1 is running\n");
    return NULL;
}
void* thread2Func(void* arg){
    printf("Thread 2 is running\n");
    return NULL;
}

int main(){
    pthread_t thread1,thread2;
    pthread_create(&thread1,NULL,thread1Func,NULL);
    pthread_create(&thread2,NULL,thread2Func,NULL);

    pthread_join(thread1,NULL);
    pthread_join(thread2,NULL);

    printf("Success!\n");
    fflush(stdout);
    return 0;
}