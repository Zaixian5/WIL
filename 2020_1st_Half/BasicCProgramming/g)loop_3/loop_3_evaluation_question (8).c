#include <stdio.h>

int main()
{
    int n;
    int i, j;
    int num=1;

    scanf("%d", &n);
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            printf("%d", num);
            num+=2;
            if(num>10) num-=10;
        }
        printf("\n");
    }
    return 0;
}
