#include <stdio.h>

int count=0; 
int process(int n)
{
    if(n==1) return count;
    if(n%2==0){
        count++;
        return process(n/2); 
    }else{
        count++;
        return process(n/3); 
    }                                
}
int main()
{
    int N;
    do{
        printf("1,000,000이하의 자연수를 입력하세요. ");
        scanf("%d", &N);
        if(N<=1000000&&N>0){
            printf("\n%d\n", process(N));
        }
        else{
            printf("잘못입력하셨습니다. 다시입력하세요.\n\n");
        }
    }while(N<=0||N>1000000);
    return 0;
}
