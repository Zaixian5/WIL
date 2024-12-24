#include <stdio.h>

int main()
{
    int pas[5][5]={0};
    int i, j;

    pas[0][0]=1;
    for(i=1;i<5;i++){
        for(j=0;j<=i;j++){
            if(j==0){
                pas[i][j]=1;
            }
            else{
                pas[i][j]=pas[i-1][j-1]+pas[i-1][j];
            }
        }
    }
    for(i=0;i<5;i++){
        for(j=0;j<=i;j++){
            printf("%d ", pas[i][j]);
        }
        printf("\n");
    }
    return 0;
}



