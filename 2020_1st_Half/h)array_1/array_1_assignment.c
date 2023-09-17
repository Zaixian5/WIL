#include <stdio.h>

int main()
{
    int n;

    printf("50이하의 정수를 입력해주세요. ");
    scanf("%d", &n);

    if(n>50) printf("잘못입력하셨습니다.\n");
    else{
        int score[n];
        int i, j;
        int ratio;
        int tmp;
        int sum=0;
        double avg;
        int min=100;
        int max=0;

        ratio=n*0.1;
        /* ratio값은 상, 하위 10%의 점수를 제외하는 계산을 위해 만든 변수이므로 의도적으로 정수형 변수로 선언하였습니다. 따라서 ratio값의 정수부분이 0인 경우 상, 하위 10%를
        제외하는 계산이 이루어지지 않습니다. 예를들어 n이 5인경우 상위(하위) 10%는 점수가 높은 학생(낮은 학생) 0.5명의 점수를 의미하는데 이 경우에는 상, 하위 10%의 점수가 제외되지
        않습니다.*/

        printf("%d명의 점수를 모두 입력해주세요.\n", n);
        for(i=0;i<n;i++){
            scanf("%d", &score[i]);
        }
        for(i=0;i<n-1;i++){
            for(j=i+1;j<n;j++){
                if(score[i]>score[j]){
                    tmp=score[i];
                    score[i]=score[j];
                    score[j]=tmp;
                }
            }
        }
        for(i=ratio;i<n-ratio;i++){
            sum+=score[i];
            if(min>=score[i]) min=score[i];
            if(max<=score[i]) max=score[i];
        }
        avg=(double)sum/(n-2*ratio);
        printf("상위 10%%, 하위 10%%를 제외한 학생들의 점수 오름차순 배열, 합, 평균, 최저점수, 최고점수를 순서대로 나타내면 다음과 같다.\n");
        for(i=ratio;i<n-ratio;i++){
            printf("%d ", score[i]);
        }
        printf("\n");
        printf("%d\n", sum);
        printf("%.2f\n", avg);
        printf("%d\n", min);
        printf("%d\n", max);
        return 0;
    }
}
