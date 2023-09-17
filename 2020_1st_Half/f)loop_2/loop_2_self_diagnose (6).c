#include <stdio.h>

int main()
{
    int n, i;
    int score;
    double avg;
    int sum=0;

    printf("과목수를 10이하의 수로 입력해 주세요.\n");
    scanf("%d", &n);

    if(n<=10){
        printf("%d개의 과목점수를 각각 입력해 주세요.\n", n);
        for(i=1;i<=n;i++){
            scanf("%d", &score);
            sum+=score;
        }
        avg=(double)sum/n;
        printf("\navg: %.1f\n", avg);

        if(avg>=80)printf("pass\n");
        else printf("fail\n");
    }
    else printf("잘못입력하셨습니다.\n");

    return 0;
}
