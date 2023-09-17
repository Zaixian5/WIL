#include <stdio.h>

int main()
{
    int a, b, c;

    scanf("%d %d", &a, &b);

    if(a>b){
        c=a;
        a=b;
        b=c;
    }

    printf("%d\n", a+100-b);

    if(a+100-b>0){
        printf("Obesity\n");
    }
    return 0;
}
