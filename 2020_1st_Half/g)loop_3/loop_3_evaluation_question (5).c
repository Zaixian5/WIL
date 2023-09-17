#include <stdio.h>

int main()
{
    int n;
    int i, j;
    int num=0;
    char alpha='A';

    scanf("%d", &n);
    for(i=1;i<=n;i++){
        for(j=1;j<=n-i+1;j++){
            printf("%c ", alpha++);
        }
        for(j=1;j<i;j++){
            printf("%d ", num++);
        }
        printf("\n");
    }
    return 0;
}
