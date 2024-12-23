// pr04_06.c

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

#define MAX_BUFF 100

int main(int argc, char* argv[]){
    if(access(argv[2], R_OK) == 0){
        printf("%s: Read permission is permitted\n", argv[2]);
    }

    if(access(argv[2], W_OK) == 0){
        printf("%s: Write permission is permitted\n", argv[2]);
    }

    if(access(argv[2], X_OK) == 0){
        printf("%s: Execute permission is permitted\n", argv[2]);
    }

    chmod(argv[2], strtol(argv[1], NULL, 8));

    return 0;
}
