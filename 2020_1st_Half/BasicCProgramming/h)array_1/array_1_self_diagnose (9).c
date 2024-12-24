#include <stdio.h>

int main()
{
    int num[10];
    int i, j, tmp;

    for(i=0;i<10;i++){
        scanf("%d", &num[i]);
    }
    for(i=0;i<9;i++){
        for(j=i+1;j<10;j++){
            if(num[i]<num[j]){
                tmp=num[i];
                num[i]=num[j];
                num[j]=tmp;
            }
        }
    }
    for(i=0;i<10;i++){
        printf("%d ", num[i]);
    }
    printf("\n");
    return 0;
}
