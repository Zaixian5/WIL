#include <stdio.h>

int main()
{
    int n;
    int i, j;
    int num=1;
    int alpha='A';

    scanf("%d", &n);
    for(i=n;i>=1;i--){
        for(j=i;j>=1;j--){
            printf("%d ", num++);
        }
        for(j=1;j<=n-i+1;j++){
            printf("%c ", alpha++);
        }
        printf("\n");
    }
    return 0;
}
