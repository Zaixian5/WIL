#include <stdio.h>
#define n 10

void input();
void output();

int main()
{
    int count[n]={0};

    input(count);
    output(count, n);
    return 0;
}
void input(int a[])
{
    int num;

    while(1){
        scanf("%d", &num);
        if(num==0) break;
        a[num%10]++;
    }
}
void output(int a[], int cnt)
{
    int i;

    for(i=0;i<cnt;i++){
        if(a[i]>0) printf("%d: %d개\n", i, a[i]);
    }
}
