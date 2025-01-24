#include <stdio.h>
#include <pthread.h>

typedef struct s_counter{
    pthread_mutex_t count_mutex;
    unsigned int count;
} t_counter;


void *thread_routine(void *data){
    pthread_t tid;
    t_counter *count;
    
    return 0;
}

int main(){
    t_counter count;

    pthread_t tid1;
    pthread_t tid2;

    




    return 0;
}