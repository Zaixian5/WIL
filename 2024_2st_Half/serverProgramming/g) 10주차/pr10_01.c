// pr10_01.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]){
    FILE* fp;
    char child_proc[BUFSIZ] = "man ";
    char result_buf[BUFSIZ];

    strcat(child_proc, argv[1]);
    fp = popen(child_proc, "r");
    
    for(int i = 0; i < 4; i++){
        fgets(result_buf, sizeof(result_buf), fp);
        printf("%s", result_buf);
    }

    pclose(fp);
    return 0;
}
