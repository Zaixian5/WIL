// pr04_04.c

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char* argv[]){
   struct stat statbuf;

   stat(argv[1], &statbuf);

   printf("SIZE = %d\n", (int)statbuf.st_size);

   return 0;
}
