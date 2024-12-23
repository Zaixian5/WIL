// pr04_07.c

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

int main(int argc, char* argv[]){
    char readlink_buff[BUFSIZ];
    char realpath_buff[BUFSIZ];

    symlink(argv[1], "link.sym");

    int n = readlink("link.sym", readlink_buff, BUFSIZ);
    readlink_buff[n] = '\0';

    realpath("link.sym", realpath_buff);

    printf("%s: READLINK = %s\n", argv[1], readlink_buff);
    printf("%s: REALPATH = %s\n", argv[1], realpath_buff);

    return(0);
}
