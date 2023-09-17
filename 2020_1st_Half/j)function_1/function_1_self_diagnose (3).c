#include <stdio.h>

void square();

int main()
{
    int n;

    scanf("%d", &n);
    square(n);

    return 0;
}
void square(int n)
{
    int i, j;
    int num=1;

    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            printf("%d ", num++);
        }
        printf("\n");
    }
}
