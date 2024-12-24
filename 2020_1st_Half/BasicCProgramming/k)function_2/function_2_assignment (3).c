#include <stdio.h>

void process();

int main()
{
    int a[100];
    process(a);
    return 0;
}
void process(int n[])
{
    int i, j, num, tmp, odd_sum=0, even_sum=0, odd_count=0, even_count=0;
    double odd_avg, even_avg;

    printf("정수 하나를 입력하세요. ");
    scanf("%d", &num);
    printf("%d를 입력하셨습니다. %d개의 정수를 입력하세요. ", num, num);
    for(i=0;i<num;i++){
        scanf("%d", &n[i]);
    }
    for(i=0;i<num;i+=2){
        odd_sum+=n[i];
        odd_count++;
    }
    for(i=1;i<num;i+=2){
        even_sum+=n[i];
        even_count++;
    }
    odd_avg=(double)odd_sum/odd_count;
    even_avg=(double)even_sum/even_count;
    for(i=0;i<num-1;i++){
        for(j=i+1;j<num;j++){
            if(n[i]>n[j]){
                tmp=n[i];
                n[i]=n[j];
                n[j]=tmp;
            }
        }
    }
    printf("입력하신 정수를 오름차순은로 정령하면 다음과 같습니다.\n");
    for(i=0;i<num;i++){
        printf("%d ", n[i]);
    }
    printf("\n\n");
    printf("홀수번째로 입력하신 정수의 함과 평균은 각각 다음과 같습니다.\n");
    printf("%d %.2f\n\n", odd_sum, odd_avg);
    printf("짝수번째로 입력하신 정수의 합과 평균은 각각 다음과 같습니다.\n");
    printf("%d %.2f", even_sum, even_avg);
}
/*main 함수에서 배열 a를 선언하고 process 함수에서 int n[]으로 매개변수를 사용하여 프로그래밍 한 것은 맞으나 함수를 하나만 만들어 구조화한 것은 여러함수를 만들어 구조화 했을시 전역변수를 사용하지 않고는
  num, odd_sum 등의 모든함수에서 공동으로 사용하여야 하는 값을 이용할 수 없기 때문입니다.*/
