#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(void){
   pid_t pid;
    
   switch(pid = fork()){
     case 0:
         system("pwd");
         break;

     case -1:
         perror("fork");
         exit(1);
         break;

     default:
         system("ls");
         break;
   }

   printf("End of fork\n");
   return 0;
}
