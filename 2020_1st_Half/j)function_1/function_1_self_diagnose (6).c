#include <stdio.h>

 int gesan(int x, int y, char op)
 {
     if(op=='+') return x+y;
     else if(op=='-') return x-y;
     else if(op=='*') return x*y;
     else if(op=='/') return x/y;
     else return 0;
 }
 int main()
 {
     int a, b;
     char c;

     scanf("%d %c %d", &a, &c, &b);
     printf("%d %c %d = %d\n", a, c, b, gesan(a, b, c));

     return 0;
 }
