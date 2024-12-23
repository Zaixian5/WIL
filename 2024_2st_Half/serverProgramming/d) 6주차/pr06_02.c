// pr06_02.c

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define MAX 100

int main(int argc, char* argv[]){
    int fd;
    char buff[MAX];
    char str[MAX];
    
    fd = open(argv[1], O_RDONLY);

    lseek(fd, 0, SEEK_SET);

    int i;
    for(i = 0; read(fd, buff, 1) == 1; i++){
        lseek(fd, 1, SEEK_CUR);
        str[i] = buff[0];
    }
    
    str[i] = '\0';
    printf("%s\n", str);

    close(fd);

    return 0;
}
