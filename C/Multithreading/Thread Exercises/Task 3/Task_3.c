#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

int num = 0;

void* thread(void* arg){
    num++;
    return (void*)num;
}

int main(){
    pthread_t thread1,thread2;

    pthread_create(&thread1,NULL,thread,NULL);
    pthread_create(&thread2,NULL,thread,NULL);

    void* out1;
    void* out2;

    pthread_join(thread1, &out1);
    pthread_join(thread2, &out2);

    printf("thread1 output: %d\nthread2 output: %d\n",(int)out1,(int)out2);
    return 0;
}