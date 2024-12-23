// pr10_02.c

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void){
    int fd[2];
    pid_t pid;
    char child_proc_message[BUFSIZ];

    pipe(fd);

    switch(pid = fork()){
        case -1:
            perror("fork");
            exit(1);
            break;

        case 0:
            close(fd[0]);
            write(fd[1], "Hello from child!", 17);
            close(fd[1]);
            break;

        default:
            close(fd[1]);
            read(fd[0], child_proc_message, 17);

            printf("Received message: %s\n", child_proc_message);
            close(fd[0]);
            break;
    }

    return 0;
}
