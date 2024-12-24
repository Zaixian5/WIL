#include <stdio.h>

void circle();

int main()
{
    double r;

    scanf("%lf", &r);

    circle(r);
    return 0;
}
void circle(double r)
{
    printf("%.2f", r*r*3.14);
}
