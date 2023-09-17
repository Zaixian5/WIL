#include <stdio.h>
#include <math.h>

int main()
{
    int n;

    do{
        printf("1이상 20이하의 정수를 입력하세요. ");
        scanf("%d", &n);
        if(n>=1&&n<=20){
            printf("%d", (int)pow(2, n));
        }
        else{
            printf("잘못입력하셨습니다. 다시입력하세요.\n\n");
        }
    }while(n<1||n>20);
    return 0;
}
