#include <stdio.h>

int main()
{
    int scan_num;
    int num=1;
    int sum=0;

    printf("100이하의 양의정수를 입력하세요.\n");
    /* 실제 자가진단2에는 100이하의 양의정수가 아니라 정수를 입력하라고 되어있지만 1에서 음수까지 더한다는 것은 개념적으로 어색하므로 이와같이 수정하였습니다. */
    scanf("%d", &scan_num);

    if(scan_num>=0&&scan_num<=100){
        while(num<=scan_num){
            sum+=num;
            num++;
        }
        printf("1부터 입력하신 수 까지의 합은 %d 입니다.\n", sum);
    }
    else {
        printf("잘못입력하셨습니다.\n");
    }
    return 0;
}
