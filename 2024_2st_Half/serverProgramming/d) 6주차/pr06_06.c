// pr06_06.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define MAX 100

typedef struct{
    int id;
    int score1;
    int score2;
    int score3;
} STUDENT;

int main(void){
    int fd;
    char buff[MAX];

    STUDENT stu1 = {0};
    STUDENT stu2 = {0};

    fd = open("./table.txt", O_RDONLY);
    
    // student1
    // -> id
    read(fd, buff, 7);
    stu1.id = atoi(buff);
    lseek(fd, 1, SEEK_CUR);
    memset(buff, 0, sizeof(buff));    

    // -> score1
    read(fd, buff, 2);
    stu1.score1 = atoi(buff);
    lseek(fd, 1, SEEK_CUR);
    memset(buff, 0, sizeof(buff));    
    
    // -> score2
    read(fd, buff, 2);
    stu1.score2 = atoi(buff);
    lseek(fd, 1, SEEK_CUR);
    memset(buff, 0, sizeof(buff));
    
    // -> score3
    read(fd, buff, 2);
    stu1.score3 = atoi(buff);
    lseek(fd, 1, SEEK_CUR);
    memset(buff, 0, sizeof(buff));

    // student2
    // -> id
    read(fd, buff, 7);
    stu2.id = atoi(buff);
    lseek(fd, 1, SEEK_CUR);
    memset(buff, 0, sizeof(buff));

    // -> score1
    read(fd, buff, 2);
    stu2.score1 = atoi(buff);
    lseek(fd, 1, SEEK_CUR);
    memset(buff, 0, sizeof(buff));

    // -> score2
    read(fd, buff, 2);
    stu2.score2 = atoi(buff);
    lseek(fd, 1, SEEK_CUR);
    memset(buff, 0, sizeof(buff));

    // -> score3
    read(fd, buff, 2);
    stu2.score3 = atoi(buff);
    lseek(fd, 1, SEEK_CUR);
    memset(buff, 0, sizeof(buff));

    printf("%d %.2f\n", stu1.id, (double)(stu1.score1 + stu1.score2) / 2);
    printf("%d %.2f\n", stu2.id, (double)(stu2.score1 + stu2.score2) / 2);

    close(fd);

    return 0;
}
