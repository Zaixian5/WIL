#include <stdio.h>

int main()
{
    int sum1=0, sum2=0;
    double avg;
    int num[10];
    int i;

    for(i=0;i<10;i++){
        scanf("%d", &num[i]);
        if(i%2==0) sum2+=num[i];
        else sum1+=num[i];
        // 배열에서 짝수 번째에 입력된 값의 i값은 홀수 이고 배열에서 홀수 번째에 입력된 값의 i값은 짝수입니다. i가 0부터 시작하기 때문에 그렇습니다.
    }
    avg=sum2/5.0;

    printf("sum: %d\n", sum1);
    printf("avg: %.1f\n", avg);
    return 0;
}
