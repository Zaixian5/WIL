#include <stdio.h>

int sum();
int main()
{
    int N;
    do{
        printf("100이하의 자연수를 입력하세요. ");
        scanf("%d", &N);
        if(N<=100&&N>0){
            printf("\n%d\n", sum(N));
        }
        else{
            printf("잘못입력하셨습니다. 다시입력하세요.\n\n");
        }
    }while(N>100||N<=0);
    return 0;
}
int sum(int n)
{
    int add;
    if(n<1) return 0;
    add=n+sum(n-1);
    return add;
}
