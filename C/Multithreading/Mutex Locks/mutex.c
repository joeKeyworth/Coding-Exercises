#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t lock;
int shared_data = 0;

void* increment(void *arg){
    pthread_mutex_lock(&lock);
    for(int i = 0; i < 2; i++){
        shared_data++;
        printf("Shared Data: %d\n",shared_data);
    }
    pthread_mutex_unlock(&lock);
    return NULL;
}

int main(){
    pthread_t thread1, thread2;
    pthread_mutex_init(&lock,NULL);
    pthread_create(&thread1,NULL,increment,NULL);
    pthread_create(&thread2,NULL,increment,NULL);
    pthread_join(thread1,NULL);
    pthread_join(thread2,NULL);
    pthread_mutex_destroy(&lock);
    return 0;
}