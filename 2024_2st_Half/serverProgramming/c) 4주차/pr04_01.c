// pr04_01.c

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

int main(int argc, char* argv[]){
    if((mkdir(argv[1], 0755)) == -1){
        perror("mkdir()");
        exit(1);
    }

    chdir(argv[1]);

    char* cwd = getcwd(NULL, BUFSIZ);
    printf("cwd: %s\n", cwd);

    free(cwd);
    return(0);
}
