#include <stdio.h>

 void sc()
 {
     puts("~!@#$^&*()_+|");
 }
 int main()
 {
     int n;
     int i;

     scanf("%d", &n);
     for(i=1;i<=n;i++){
        sc();
     }
     return 0;
 }
