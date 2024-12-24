#include <stdio.h>

int main()
{
    int n;
    int i, j;
    int pas[11][11]={0};

    scanf("%d",&n);
    pas[n][1]=1;
    for(i=n-1;i>0;i--){
		for(j=1;j<=(n+1)-i;j++){
			pas[i][j]=pas[i+1][j-1]+pas[i+1][j];
		}
	}
    for(i=1;i<=n;i++){
		for(j=1;j<=(n+1)-i;j++){
			printf("%d ", pas[i][j]);
		}
		printf("\n");
    }
    return 0;
}
