#include <stdio.h>

int a[100];      
                  /*input 함수에서 입력받은 num 값이 이 배열의 크기가 되어야겠지만 여기서 배열을 int a[num]과 같이 선언하는 것은 불가능 하므로 충분히 큰 수인
                  100으로 배열을 구성하였습니다. 따라서 input 함수의 num 값은 100이하의 수로 입력하여야 합니다.*/
                  
int num;
int odd_sum=0, even_sum=0;
double odd_avg, even_avg;

void input();
void calculation();
void output();

int main()
{
    input();
    calculation();
    output();
    return 0;
}
void input()
{
    int i;

    printf("정수 하나를 입력해 주세요. ");
    scanf("%d", &num);
    printf("%d를 입력하셨습니다. %d개의 정수를 입력해 주세요. ", num, num);
    for(i=0;i<num;i++){
        scanf("%d", &a[i]);
    }
}
void calculation()
{
    int i, j, tmp;
    int odd_count=0, even_count=0;

    for(i=0;i<num;i+=2){
        odd_sum+=a[i];
        odd_count++;
    }
    for(i=1;i<num;i+=2){
        even_sum+=a[i];
        even_count++;
    }
    odd_avg=(double)odd_sum/odd_count;
    even_avg=(double)even_sum/even_count;

    for(i=0;i<num-1;i++){
        for(j=i+1;j<num;j++){
            if(a[i]>a[j]){
                tmp=a[i];
                a[i]=a[j];
                a[j]=tmp;
            }
        }
    }
}
void output()
{
    int i;

    printf("\n입력하신 정수를 오름차순으로 정렬하면 다음과 같습니다.\n");
    for(i=0;i<num;i++){
        printf("%d ", a[i]);
    }
    printf("\n\n");
    printf("홀수번째로 입력하신 정수의 합과 평균은 각각 다음과 같습니다.\n");
    printf("%d, %.2f\n\n", odd_sum, odd_avg);
    printf("짝수번째로 입력하신 정수의 합과 평균은 각각 다음과 같습니다.\n");
    printf("%d, %.2f\n", even_sum, even_avg);
}
