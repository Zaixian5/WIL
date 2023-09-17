#include <stdio.h>

int n, m;
int i, j;
double student_sum[100]={0};
double subject_sum[100]={0};
double score[100][100];
//전역변수를 double score[i][j]등 과 같이 선언할 수 없으므로 충분히 큰 수인 100을 사용하였습니다. 따라서 학생수와 과목수는 99개 이하의 수로 입력하여야 합니다.
//(for 문의 변수를 1부터 시작하도록 구성하였기 때문에 100개 이하가 아니라 99개 이하입니다.)

void input1();
void input2();
void cal();
void output();

int main()
{
    input1();
    input2();
    cal();
    output();
    return 0;
}
void input1()
{
    printf("학생수를 입력하세요. ");
    scanf("%d", &n);
    printf("과목수를 입력하세요. ");
    scanf("%d", &m);
}
void input2()
{
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            printf("%d번쨰 학생의 %d번째 과목의 점수를 입력하세요. ", i, j);
            scanf("%lf", &score[i][j]);
        }
        printf("\n");
    }
}
void cal()
{
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            student_sum[i]+=score[i][j];
        }
    }
    for(j=1;j<=m;j++){
        for(i=1;i<=n;i++){
            subject_sum[j]+=score[i][j];
        }
    }
}
void output()
{
    printf("학생별 총점:\n");
    for(i=1;i<=n;i++){
        printf("%d번째 학생의 과목 총점: %.2f\n", i, student_sum[i]);
    }
    printf("\n");
    printf("과목별 총점:\n");
    for(j=1;j<=m;j++){
        printf("%d번째 과목의 총점: %.2f\n", j, subject_sum[j]);
    }
    printf("\n");
}
