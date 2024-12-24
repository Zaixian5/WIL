#include <stdio.h>

int main()
{
    int n;
    int i, j;
    int num=1;

    scanf("%d", &n);
    for(i=1;i<=n;i++){
        for(j=1;j<=i-1;j++){
            printf(" ");
        }
        for(j=n;j>=i;j--){
            printf("%d", num++);
        }
        printf("\n");
    }
}
