#include <stdio.h>

 int arr[100]={0,1};
 int num();
 int main()
 {
     int N;
     do{
        printf("50이하의 자연수를 입력하세요. ");
        scanf("%d", &N);
        if(N<=50&&N>0){
            printf("\n%d\n", num(N));
        }
        else{
            printf("잘못입력하셨습니다. 다시입력하세요.\n\n");
        }
     }while(N>50||N<=0);
     return 0;
 }
 int num(int n)
 {
     if(arr[n]==0){
        arr[n]=num(n/2)+num(n-1);
     }
     return arr[n];
 }
