// pr04_03.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>

int main(int argc, char* argv[]){
   DIR* dp = opendir(".");
   struct dirent* dent;
   int is_exist = 0; // 0: not exist 1: exist

   while((dent = readdir(dp)) != NULL){
        if(dent->d_type != DT_REG){
            continue;
        }
        if(strcmp(dent->d_name, argv[1]) == 0){
            is_exist = 1;
        }     
   }

   if(is_exist){
        printf("File \'%s\' exists in the current directory.\n", argv[1]);
   }
   else{
        printf("File \'%s\' does not exist in the current directory.\n", argv[1]);
   }

   return(0);
}
