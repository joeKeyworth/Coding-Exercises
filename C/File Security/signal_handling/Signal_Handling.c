#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

void int_handler(int);

int main(){
    signal(SIGINT, int_handler);
    
    while(1){
        printf("Press ctrl+c to escape\n");
        fflush(stdout);
        sleep(1);
    }

}

void int_handler(int){
    printf("program has been interrupted by user\n");
    exit(1);
}