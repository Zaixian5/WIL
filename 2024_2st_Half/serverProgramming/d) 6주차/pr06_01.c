// pr06_01.c

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define MAX 100

int main(int argc, char* argv[]){
    int fd_s;
    int fd_d;
    int n;
    char buff[MAX];

    fd_s = open(argv[1], O_RDONLY);
    fd_d = open(argv[2], O_CREAT | O_WRONLY, 0644);

    while((n = read(fd_s, buff, 1)) != 0 ){
        write(fd_d, buff, n);
    }

    close(fd_s);
    close(fd_d);

    return 0;
}
