#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LENGTH 21

int main(){
    char* userInput = malloc(MAX_LENGTH);

    printf("Enter a string that is less than 20 characters long, with only letters in it\n");
    bool isValid = true;
    if(fgets(userInput,MAX_LENGTH,stdin) != NULL){
        for(int i = 0; i < strlen(userInput) - 1; i++){
            if((userInput[i] > 64 && userInput[i] < 91) | (userInput[i] > 96 && userInput[i] < 123) == false){
                isValid = false;
            }
        }
    } else{
        printf("Error reading input\n");
    }

    if(isValid){
        printf("%s", userInput);
    } else{
        printf("Error: Unexpected Symbol\n");
    }

}