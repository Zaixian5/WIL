#include <stdio.h>

int main()
{
    int a, b;
    int i, j;

    printf("a단 부터 b단 까지 구구단을 출력하는 프로그램입니다.\n");
    printf("2부터 9사이의 정수 a와 b를 각각 입력해주세요.\n");

    printf("a ");
    scanf("%d", &a);
    printf("b ");
    scanf("%d", &b);

    if(a>=2&&a<=9&&b>=2&&b<=9&&a!=b){
        if(a<b){
            for(i=1;i<=9;i++){
                for(j=a;j<=b;j++){
                    printf("%d * %d = %d   ", j, i, i*j);
                }
                printf("\n");
            }
        }
        if(a>b){
            for(i=1;i<=9;i++){
                for(j=a;j>=b;j--){
                    printf("%d * %d = %d   ", j, i, i*j);
                }
                printf("\n");
            }
        }
    }
    else{
        printf("잘못입력하셨습니다.\n");
    }
    return 0;
}
