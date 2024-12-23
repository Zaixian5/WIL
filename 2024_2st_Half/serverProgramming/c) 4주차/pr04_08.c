// pr04_08.c

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char* argv[]){
    struct stat statbuf;

    stat(argv[1], &statbuf);
    printf("Before Link Count = %d\n", (int)statbuf.st_nlink);

    link(argv[1], "link.ln");

    stat(argv[1], &statbuf);
    printf("After Link Count = %d\n", (int)statbuf.st_nlink);

    unlink("link.ln");

    stat(argv[1], &statbuf);
    printf("After Unlink Count = %d\n", (int)statbuf.st_nlink);

    return(0);
}
