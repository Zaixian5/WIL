#include <stdio.h>

int max();

int main()
{
    int a, b, c;

    scanf("%d %d %d", &a, &b, &c);
    printf("%d", max(a, b, c));

    return 0;
}
int max(int x, int y, int z)
{
    if(x>y&&x>z){
        return x;
    }
    else if(y>x&&y>z){
        return y;
    }
    else{
        return z;
    }
}
