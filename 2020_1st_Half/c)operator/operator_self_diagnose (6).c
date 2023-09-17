#include <stdio.h>

int main()
{
    int a, b;
    int result1, result2, result3, result4;

    scanf("%d %d", &a, &b);

    result1=(a>b);
    result2=(a<b);
    result3=(a>=b);
    result4=(a<=b);

    printf("4>5---%d\n", result1);
    printf("4<5---%d\n", result2);
    printf("4>=5---%d\n", result3);
    printf("4<=5---%d\n", result4);

    return 0;
}
