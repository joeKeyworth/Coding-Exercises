#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define FULL_ACCESS 0777
#define READ_ONLY 0444


int main(){
    FILE* file;
    char* filename = "readOnly.txt";

    file = fopen(filename, "r");
    if(errno == 2){
        int fileHandle = open(filename, O_WRONLY | O_CREAT, READ_ONLY);      
        close(fileHandle); 
    }

    FILE* fullFile;
    char* Ffilename = "fullAccess.txt";

    file = fopen(Ffilename,"r");
    if(errno==2){
        int fileHandle = open(Ffilename, O_WRONLY | O_CREAT, FULL_ACCESS);
        close(fileHandle);
    }   

    return 0;
}