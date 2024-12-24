#include <stdio.h>

void word(int n)
{
    if(n<1) return;
    word(n-1);
    printf("recursive\n");
}
int main()
{
    int N; //N은 자연수 입니다.

    scanf("%d", &N);
    if(N<=0) return 0; //N은 자연수이므로 자연수가 아닌 수가 입력되면 프로그램을 종료합니다.
    word(N);
    return 0;
}
