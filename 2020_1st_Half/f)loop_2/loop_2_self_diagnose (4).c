#include <stdio.h>

int main()
{
    int i, num;
    int sum=0;

    printf("100이하의 정수를 입력하세요. ");
    scanf("%d", &num);

    if(num<=100){
        for(i=num;i<=100;i++){
            sum+=i;
        }
        printf("입력한 수 부터 100까지의 합은 %d 입니다.\n", sum);
    }
    else{
        printf("잘못입력하셨습니다.\n");
    }
    return 0;
}
