#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void){
    char* argv[] = {"date", NULL};
    pid_t pid;
    int status;

    switch(pid = fork()){
        case -1:
            perror("fork");
            exit(1);
            break;

        case 0:
            execv("/usr/bin/date", argv);
            break;
        
        default:
            while(waitpid(pid, &status, WNOHANG) == 0){
                sleep(1);
            }
            printf("Child Exit Status: %d\n", status);
            break;
    }

    return 0;
}
