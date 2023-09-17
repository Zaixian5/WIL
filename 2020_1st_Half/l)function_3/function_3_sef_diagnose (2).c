#include <stdio.h>

void number(int n)
{
    printf("%d ", n);
    if(n>1) number(n-1);
}
int main()
{
    int N;

    do{
        printf("50이하의 자연수를 입력하세요. ");
        scanf("%d", &N);
        if(N<=50&&N>0){
            printf("\n");
            number(N);
            printf("\n");
        }
        else printf("잘못입력하셨습니다. 다시입력하세요.\n\n");

    }while(N<=0||N>50);

    return 0;
}
