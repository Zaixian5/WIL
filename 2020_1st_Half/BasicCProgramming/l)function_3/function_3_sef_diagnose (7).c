#include <stdio.h>

int process(int mul)
{
    int n;
    if(mul==0) return 1;
    n=mul%10;
    if(n==0) n=1;
    mul/=10;
    return n*process(mul);
}
int main()
{
    int a, b, c;
    do{
        printf("3자리 자연수 3개를 입력하세요. ");
        scanf("%d %d %d", &a, &b, &c);
        if(a/100>=1&&a/100<=9&&b/100>=1&&b/100<=9&&c/100>=1&&c/100<=9){
            printf("\n%d\n", process(a*b*c));
        }
        else{
            printf("잘못입력하셨습니다. 다시입력하세요.\n\n");
        }
    }while(a/100<1||a/100>=10||b/100<1||b/100>=10||c/100<1||c/100>=10);
    return 0;
}
