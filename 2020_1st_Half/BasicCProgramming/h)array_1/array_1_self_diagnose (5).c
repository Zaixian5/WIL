#include <stdio.h>

int main()
{
    double score[7]={0, 85.6, 79.5, 83.1, 80.0, 78.2, 75.0};
    int n, i;
    double sum;

    scanf("%d %d", &n, &i);
    sum=score[n]+score[i];
    printf("%.1f\n", sum);

    return 0;
}
