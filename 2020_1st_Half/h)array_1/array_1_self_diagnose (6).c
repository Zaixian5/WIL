#include <stdio.h>

int main()
{
    int num[10];
    int min=1001; //1000을 넘지 않는다는 것은 1000까지는 가능하다는 의미로 해석 하였습니다. 
    int i;

    for(i=0;i<10;i++){
        scanf("%d", &num[i]);
    }
    for(i=0;i<10;i++){
        if(min>num[i]) min=num[i];
    }
    printf("%d\n", min);
    return 0;
}
