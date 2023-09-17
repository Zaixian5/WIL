#include <stdio.h>

int main()
{
    int n;
    int i, j;
    int alpha='A';

    scanf("%d", &n);
    for(i=n;i>=1;i--){
        for(j=1;j<=i;j++){
            printf("%c", alpha++);
        }
        printf("\n");
    }
    return 0;
}
