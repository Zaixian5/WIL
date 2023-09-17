#include <stdio.h>
#include <math.h>

int main()
{
    double a, b, c;
    double sum1, sum2;
    double avg1, avg2;
    int round1, round2;

    scanf("%lf %lf %lf", &a, &b, &c);
    sum1=a+b+c;
    avg1=sum1/3;
    round1=floor(avg1+0.5);
    sum2=floor(a+0.5)+floor(b+0.5)+floor(c+0.5);
    avg2=sum2/3;
    round2=floor(avg2+0.5);

    printf("%d\n", round1);
    printf("%d\n", round2);
    return 0;
}
