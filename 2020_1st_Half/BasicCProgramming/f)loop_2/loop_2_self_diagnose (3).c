#include <stdio.h>

int main()
{
    int num;
    int i;
    printf("2이상 50이하의 수를 입력하세요. ");
    scanf("%d", &num);
    if(num<=50&&num>=2){
        for(i=2;i<=num;i+=2){
            printf("%d ", i);
        }
    }
    else{
        printf("잘못입력하셨습니다.");
    }
    return 0;
}
