// pr04_02.c

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char* argv[]){
    DIR* dp = opendir(argv[1]);

    if(dp == NULL){
        perror("opendir()");
        exit(1);
    }

    struct dirent* dent;

    int is_empty = 0; // 0: empty 1: not empty

    while((dent = readdir(dp)) != NULL){
        if(strcmp(dent->d_name, ".") != 0 && strcmp(dent->d_name, "..") != 0){
            is_empty = 1;
        }
    }
    
    if(is_empty){
        printf("The directory \'%s\' is not empty\n", argv[1]);
    }
    else{
        printf("The directory \'%s\' is empty\n", argv[1]);
        rmdir(argv[1]);
        printf("The directory \'%s\' has been deleted\n", argv[1]);
    }

    closedir(dp);
    return(0);
}
