#include <stdio.h>

int main()
{
    int n;
    int i, j;

    scanf("%d", &n);
    for(i=0;i<n;i++){
        for(j=n-i;j<n;j++){
            printf(" ");
        }
        for(j=i*2;j<n*2-1;j++){
            printf("*");
        }
        printf("\n");
    }
    return 0;
}
