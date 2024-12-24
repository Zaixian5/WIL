#include <stdio.h>
#include <stdlib.h>
#define n 5

int main()
{
    int i;
    int a[n];
    int b[n];
    int sum=0;

    for(i=0;i<n;i++){
        scanf("%d", &a[i]);
    }
    for(i=0;i<n;i++){
        b[i]=abs(a[i]);
        sum+=b[i];
    }
    printf("%d", sum);
    return 0;
}
