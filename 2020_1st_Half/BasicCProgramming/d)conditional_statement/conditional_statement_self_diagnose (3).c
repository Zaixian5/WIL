#include <stdio.h>

int main()
{
    int a;
    scanf("%d", &a);
    if(a>=20){
        printf("adult\n");
    }
    else{
        printf("%d years later\n", 20-a);
    }
    return 0;
}
