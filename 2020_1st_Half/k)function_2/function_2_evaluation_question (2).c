#include <stdio.h>
#include <math.h>

int main()
{
    double a, b;
    int c, d;
    int num;
    int tmp;

    scanf("%lf %lf", &a, &b);
    if(a>b){
        tmp=a;
        a=b;
        b=tmp;
    }
    c=(int)sqrt(a);
    d=(int)sqrt(b);

    if(c==sqrt(a)) num=d-c+1;
    if(c!=sqrt(a)) num=d-c;
    printf("%d", num);
    return 0;
}
