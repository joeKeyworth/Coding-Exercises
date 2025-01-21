#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 20

int main(){
    printf("Enter your name: ");    
    char *name = malloc(MAX_NAME_LEN);
    
    if(fgets(name,MAX_NAME_LEN,stdin) != NULL){
        printf("Hello %s\n", name);
    } else{
        printf("Error reading input");
    }
}