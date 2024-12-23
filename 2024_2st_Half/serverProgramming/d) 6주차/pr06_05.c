// pr06_05.c

#include <stdio.h>

#define MAX 100

int main(int argc, char* argv[]) {
    FILE* fp;
    char buff[MAX];
    char str[MAX];
    
    fp = fopen(argv[1], "r");

    fseek(fp, 0, SEEK_SET);

    int i;
    for(i = 0; fread(buff, sizeof(char), 1, fp) == 1; i++){
       fseek(fp, 1, SEEK_CUR);
       str[i] = buff[0]; 
    }

    str[i] = '\n';
    str[i + 1] = '\0';
    
    fwrite(str, sizeof(char), i + 1, stdout);
    fclose(fp);

    return 0;
}
