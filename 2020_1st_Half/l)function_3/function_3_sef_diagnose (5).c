#include <stdio.h>

 int arr[101]={0, 1, 2};
 int sequence();
 int main()
 {
     int N;
     do{
        printf("100이하의 자연수를 입력하세요. ");
        scanf("%d", &N);
        if(N<=100&&N>0){
            printf("\n%d\n", sequence(N));
        }
        else{
            printf("잘못입력하셨습니다. 다시 입력하세요.\n\n");
        }
     }while(N>100||N<=0);
     return 0;
 }
 int sequence(int n)
 {
     if(arr[n]==0){
        arr[n]=(sequence(n-2)*sequence(n-1))%100;
     }
     return arr[n];
 }
