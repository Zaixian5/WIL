#include <stdio.h>

int main()
{
    int i, j;
    int horizontal_sum[4]={0};
    int vertical_sum[4]={0};
    int total_sum=0;
    int horizontal_avg[4];
    int vertical_avg[2];
    int total_avg;
    int a[4][2]={{0}};

    for(i=0;i<4;i++){
        for(j=0;j<2;j++){
            scanf("%d", &a[i][j]);
            total_sum+=a[i][j];
        }
    }
    for(i=0;i<4;i++){
        for(j=0;j<2;j++){
            horizontal_sum[i]+=a[i][j];
        }
    }
    for(j=0;j<2;j++){
        for(i=0;i<4;i++){
            vertical_sum[j]+=a[i][j];
        }
    }
    total_avg=total_sum/8;
    for(i=0;i<4;i++){
        horizontal_avg[i]=horizontal_sum[i]/2;
    }
    for(i=0;i<2;i++){
        vertical_avg[i]=vertical_sum[i]/4;
    }
    for(i=0;i<4;i++){
        printf("%d ", horizontal_avg[i]);
    }
    printf("\n");
    for(i=0;i<2;i++){
        printf("%d ", vertical_avg[i]);
    }
    printf("\n");
    printf("%d\n", total_avg);
    return 0;
}
