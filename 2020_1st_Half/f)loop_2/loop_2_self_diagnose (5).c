#include <stdio.h>

int main()
{
    int i, num;
    int count1=0;
    int count2=0;

    for(i=1;i<=10;i++){
        scanf("%d", &num);
        if(num%3==0){
            count1++;
        }
        if(num%5==0){
            count2++;
        }
    }
    printf("Multiple of 3: %d\n", count1);
    printf("Multiple of 5: %d\n", count2);

    return 0;
}
