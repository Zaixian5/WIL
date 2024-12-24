#include <stdio.h>

int main()
{
    double a=2.1;
    double b=91.44;

    printf("%4.1fyd=%5.1fcm\n", a, a*b);

    a=10.5;
    b=2.54;

    printf("%4.1fin=%5.1fcm\n", a, a*b);

    return 0;
}
