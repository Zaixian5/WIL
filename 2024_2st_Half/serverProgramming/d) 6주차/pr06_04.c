// pr06_04.c

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define MAX 100

int main(int argc, char* argv[]) {
    char buff[MAX];
    int fd;

    fd = open(argv[1], O_WRONLY);

    dup2(fd, 1); // 1: Standard Output

    while(1){
        if (fgets(buff, sizeof(buff), stdin) != NULL) {
            printf("%s", buff);
        }
        else{
            break;
        }
    }

    close(fd);

    return 0;
}

