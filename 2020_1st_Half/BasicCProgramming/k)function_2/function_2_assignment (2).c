#include <stdio.h>

int num, i;
int count[10]={0};

void input();
void output();

int main()
{
    input();
    output();
    return 0;
}
void input()
{
    while(1){
        scanf("%d", &num);
        if(num==0) break;
        count[num%10]++;
    }
}
void output()
{
    for(i=0;i<10;i++){
        if(count[i]>0) printf("%d: %d개\n", i, count[i]);
    }
}
