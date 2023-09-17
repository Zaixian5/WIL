#include <stdio.h>

 int power();

 int main()
 {
     int a, b;

     scanf("%d %d", &a, &b);
     printf("%d\n", power(a, b));

     return 0;
 }
 int power(int x, int y)
 {
     int i;
     int num=1;

     for(i=1;i<=y;i++){
        num*=x;
     }
     return num;
 }