#include <stdio.h>

int main()
{
    int num[10];
    int max=0, min=10000;
    int i;

    for(i=0;i<10;i++){
        scanf("%d", &num[i]);
    }
    for(i=0;i<10;i++){
        if(num[i]<100&&num[i]>=1){
            if(max<num[i]){
                max=num[i];
            }
        }
        if(num[i]>=100&&num[i]<10000){
            if(min>num[i]){
                min=num[i];
            }
        }
    }
    printf("%d %d\n", max, min);
    return 0;
}
