#include <stdio.h>
#define SWAP(x, y){int z=x; x=y; y=z;}

int main()
{
    int student;
    char name[100];
    double height[100], weight[100];
    double h_sum=0, w_sum=0;
    double h_avg, w_avg;
    int menu;
    int i, j;
    printf("학생 수를 입력하세요. ");
    scanf("%d", &student);
    printf("%d명의 학생의 정보를 입력하세요. 이름(영어 성 한글자), 키, 몸무게 순으로 입력하세요.\n\n", student);
    for(i=0;i<student;i++){
        printf("%d번째 학생의 정보 ", i+1);
        scanf(" %c %lf %lf", &name[i], &height[i], &weight[i]);
    }
    printf("\n");
    for(i=1;i<student;i++){
        for(j=0;j<student-i;j++){
            if(name[j]>name[j+1]){
                SWAP(name[j], name[j+1]);
            }
            if(height[j]>height[j+1]){
                SWAP(height[j], height[j+1]);
            }
            if(weight[j]>weight[j+1]){
                SWAP(weight[j], weight[j+1]);
            }
        }
    }
    for(i=0;i<student;i++){
        h_sum+=height[i];
        w_sum+=weight[i];
    }
    h_avg=h_sum/student;
    w_avg=w_sum/student;
    while(1){
        printf("\n메뉴: 1. 이름정렬, 2. 키정렬, 3. 몸무게정렬, 4. 평균, 5. 종료\n");
        printf("메뉴를 입력하세요. ");
        scanf("%d", &menu);
        switch(menu)
        {
        case 1:
                printf("\n이름정렬을 선택하셨습니다.\n");
                for(i=0;i<student;i++){
                    printf("%c ", name[i]);
                }
                printf("\n");
                break;
        case 2:
                printf("\n키정렬을 선택하셨습니다.\n");
                for(i=0;i<student;i++){
                    printf("%.1f ", height[i]);
                }
                printf("\n");
                break;
        case 3:
                printf("\n몸무게정렬을 선택하셨습니다.\n");
                for(i=0;i<student;i++){
                    printf("%.1f ", weight[i]);
                }
                printf("\n");
                break;
        case 4:
                printf("\n평균을 선택하셨습니다.\n");
                printf("Average Height: %.1f\n", h_avg);
                printf("Average Weight: %.1f\n", w_avg);
                break;
        case 5:
                printf("\n프로그램을 종료합니다.\n");
                return 0;
                break;
        default:
                printf("\n잘못입력하셨습니다.\n");
                break;
        }
    }
    return 0;
}
