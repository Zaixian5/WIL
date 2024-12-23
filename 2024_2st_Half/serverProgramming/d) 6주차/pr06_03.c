// pr06_03.c

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
    FILE* fp;
    char c;
    int is_exit = 0;

    fp = fopen(argv[1], "r");

    while((c = fgetc(fp)) != EOF){
        if(c == '@'){
            printf("My precious!\n");
            is_exit = 1;
        }
    }

    if(is_exit == 0){
        printf("Where is my precious?\n");
    }

    fclose(fp);
    return 0;
}
