#include <stdio.h>

int a, b;
int i, j;
int mul[10][10];
//행렬에서 행은 단을, 열은 곱해지는 수(1~9)를 의미합니다.
//행은 b-a+1개가, 열은 9개가 필요하지만, 전역변수를 int mul[b-a+1][9] 와 같이 선언하는것은 불가능 하므로 구구단 계산값을 저장하기에 충분한 크기인 10으로 행과 열을 구성하였습니다.

void input();
void cal();
void output();
int main()
{
    input();
    cal();
    output();
    return 0;
}
void input()
{
    scanf("%d %d", &a, &b);
}
void cal()
{
    for(i=a;i<=b;i++){
        for(j=1;j<=9;j++){
            mul[i][j]=i*j;
        }
    }
}
void output()
{
    for(i=a;i<=b;i++){
        printf("== %ddan ==\n", i);
        for(j=1;j<=9;j++){
            printf("%d*%d=%d\n", i, j, mul[i][j]);
        }
        printf("\n");
    }
}
