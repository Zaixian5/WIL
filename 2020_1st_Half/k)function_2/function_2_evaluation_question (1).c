#include <stdio.h>
#define SWAP(x, y) {int z=x; x=y; y=z;}

void process();

int main()
{
    int arr[15];

    process(arr);
    return 0;
}
void process(int num[])
{
    int N;
    int i, j;

    do{
        printf("1이상 15이하의 정수를 입력하세요. ");
        scanf("%d", &N);
        if(N<=15&&N>=1){
            printf("%d개의 정수를 입력하세요. ", N);
            for(i=0;i<N;i++){
                scanf("%d", &num[i]);
            }
        }
        else{
            printf("잘못입력하셨습니다. 다시입력하세요.\n\n");
        }
    }while(N>15||N<1);
    for(i=1;i<N;i++){
        for(j=0;j<N-i;j++){
            if(num[j]<num[j+1]){
                SWAP(num[j], num[j+1]);
            }
        }
    }
    printf("\n");
    for(i=0;i<N;i++){
        printf("%d ", num[i]);
    }
    printf("\n");
}
