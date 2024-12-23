#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void){
    pid_t pid;
    int status;

    switch(pid = fork()){
        case -1:
            perror("fork");
            exit(1);
            break;

        case 0:
            printf("--> Child Process\n");
            execlp("sleep", "sleep", "5", (char*)NULL);
            break;

        default:
            printf("--> Parent Process\n");
            while(waitpid(pid, &status, WNOHANG) == 0){
                printf("Parent Still Wait\n");
                sleep(1);
            }

            printf("Child Exit Status: %d\n", status);
    }

    return 0;
}
