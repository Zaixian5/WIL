#include <stdio.h>

int main()
{
    int i, j, k;
    int a[4][4], b[4][4];
    int sum[4][4];
    int dif[4][4];
    int ab_mul[4][4];
    int ba_mul[4][4];
    int a_pow[4][4];
    int b_pow[4][4];

    printf("4x4행렬 A, B를 각각 입력하세요.\n");
    for(i=0;i<4;i++){
        printf("행렬A의 %d 행 ", i+1);
        for(j=0;j<4;j++){
            scanf("%d", &a[i][j]);
        }
    }
    printf("\n");
    for(i=0;i<4;i++){
        printf("행렬B의 %d 행 ", i+1);
        for(j=0;j<4;j++){
            scanf("%d", &b[i][j]);
        }
    }
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            sum[i][j]=a[i][j]+b[i][j];
            dif[i][j]=a[i][j]-b[i][j];
        }
    }
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            int s=0;
            int p=0;
            int q=0;
            int r=0;
            for(k=0;k<4;k++){
                s+=a[i][k]*b[k][j];
                p+=b[i][k]*a[k][j];
                q+=a[i][k]*a[k][j];
                r+=b[i][k]*b[k][j];
            }
            ab_mul[i][j]=s;
            ba_mul[i][j]=p;
            a_pow[i][j]=q;
            b_pow[i][j]=r;
        }
    }
    printf("\nA+B= \n");
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            printf("%d ", sum[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("A-B= \n");
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            printf("%d ", dif[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("AB= \n");
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            printf("%d ", ab_mul[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("BA= \n");
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            printf("%d ", ba_mul[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("A^2= \n");
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            printf("%d ", a_pow[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("B^2= \n");
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            printf("%d ", b_pow[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    return 0;
}
