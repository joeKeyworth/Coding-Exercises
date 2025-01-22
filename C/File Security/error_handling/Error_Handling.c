#include <stdio.h>
#include <errno.h>
#include <string.h>

int main(){

    FILE* file;
    
    file = fopen("thisFileDoesNotExist.txt", "r");
    printf("Error: %s\n", strerror(errno));    

    return 0;
}