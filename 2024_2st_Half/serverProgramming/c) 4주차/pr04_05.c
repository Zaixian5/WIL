// pr04_05.c

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

#define MAX_BUFF 100

int main(void){
    DIR* dp;
    struct dirent* dent;
    struct stat statbuf;

    int str_count = 0;
    char* file_name[MAX_BUFF];

    dp = opendir(".");
    for(; (dent = readdir(dp)) != NULL && str_count < MAX_BUFF; str_count++){
        file_name[str_count] = dent->d_name;
    }

    for(int i = 0; i < str_count; i++){
        stat(file_name[i], &statbuf);
        printf("Name: %s Inode: %d\n", file_name[i], (int)statbuf.st_ino);
    }

    closedir(dp);
    return(0);
}
