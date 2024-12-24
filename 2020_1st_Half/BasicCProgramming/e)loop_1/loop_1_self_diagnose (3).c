#include <stdio.h>

 int main()
 {
     int score;

     while(1){
        printf("number?");
        scanf("%d", &score);
        if(score>0)
            printf("positive integer\n");
        if(score<0)
            printf("negative integer\n");
        if(score==0)
            break;
     }
     return 0;
 }
