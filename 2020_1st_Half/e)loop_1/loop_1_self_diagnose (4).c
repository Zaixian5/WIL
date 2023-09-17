#include <stdio.h>

int main()
{
    int num;
    int sum=0;
    int cnt=0;
    double avg;

    while(1){
        scanf("%d", &num);
        sum+=num;
        cnt++;
        if(num>=100) break;
    }
    avg=(double)sum/cnt;

    printf("%d\n", sum);
    printf("%.1f\n", avg);

    return 0;
}
