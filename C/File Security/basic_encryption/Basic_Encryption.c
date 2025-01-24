#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 30

int main(){
    time_t key;
    time(&key);
    
    printf("Input your message (max 30 characters):\n");
    
    //Encryption
    char* name = malloc(MAX_LENGTH);
    fgets(name, MAX_LENGTH, stdin);
    //using the current system time as a key
    printf("\nkey is: %x\n\n", key);

    int *enc = malloc(strlen(name) * sizeof(int));
    int segKey = key & 0x00ff; 
    
    //multiply each character by the first two bytes of the key to form new encrypted message
    for(int i = 0; i < strlen(name) - 1; i++){
        int encChar = name[i] * segKey;
        enc[i] = encChar;
        printf("check %x * %x = %x %c\n", segKey,name[i], encChar, name[i]);
        fflush(stdout);
    }

    printf("\nEncrypted message: ");
    for(int a = 0; a < strlen(name) - 1; a++){
        printf("%x", enc[a]);
    }
    printf("\nUnencrypted message: ");

    free(name);
    //Decryption
    char* unenname = malloc(MAX_LENGTH);
    for(int i = 0; i < MAX_LENGTH; i++){
        unenname[i] = enc[i] / segKey;
    }
    unenname[MAX_LENGTH] = '\0';
    printf("%s\n", unenname);  



    
}