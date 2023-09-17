#include <stdio.h>

int main()
{
    double a, b;
    char c;

    scanf("%lf", &a);
    scanf("%lf", &b);
    scanf(" %c", &c);

    printf("%.2f\n", a);
    printf("%.2f\n", b);
    printf("%c\n", c);

    return 0;
}
