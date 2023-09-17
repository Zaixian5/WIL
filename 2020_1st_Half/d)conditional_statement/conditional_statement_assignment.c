#include <stdio.h>

int main()
{
    int num;
    int a;
    int b;
    int c;
    int d;
    double e;

    printf("1. 삼각형\n");
    printf("2. 사각형\n");
    printf("3. 원\n");
    printf("도형을 선택하세요.\n");
    scanf("%d", &num);


    switch (num)
    {
        case 1: printf("삼각형을 선택하셨습니다. 밑변과 높이를 입력하세요.\n\n");
                printf("밑변\n");
                scanf("%d", &a);
                printf("높이\n");
                scanf("%d", &b);
                printf("입력한 삽각형의 넓이는 %d 입니다.\n", a*b/2);
                break;
        case 2: printf("사각형을 선택하셨습니다. 가로와 세로를 입력하세요.\n\n");
                printf("가로\n");
                scanf("%d", &c);
                printf("세로\n");
                scanf("%d", &d);
                printf("입력한 사각형의 넓이는 %d 입니다.\n", c*d);
                break;
        case 3: printf("원을 선택하셨습니다. 반지름을 입력하세요.\n\n");
                printf("반지름\n");
                scanf("%lf", &e);
                printf("입력한 원의 넓이는 %f 입니다.", e*e*3.14);
                break;
        default:
                  printf("no supported diagram");
    }

    return 0;
}
