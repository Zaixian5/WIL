#include <stdio.h>

int main()
{
    int i, a[10];
    int n=1;

    for(i=0;i<10;i++){
        a[i]=n+i;
    }
    for(i=0;i<10;i++){
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}
