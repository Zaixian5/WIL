#include <stdio.h>
#define SWAP(x, y) {int z=x; x=y; y=z;}

int main()
{
    int i, j, k;
    int n, m;
    int arr[100]; /*배열을 입려받기 위해 충분히 큰 수인 100으로 배열을 선언하였습니다. 사실 밑에서 입력받는 n값이 이 배열의 크기가 되어야 겠지만
                    정확히 입력받는 n 만큼만 배열을 선언하는 방법은 잘 모르겠습니다.*/

    printf("자료의 개수를 입력하세요. ");
    scanf("%d", &n);
    printf("중간라운드를 입력하세요. ");
    scanf("%d", &m);
    printf("%d개의 정수를 입력하세요. ", n);
    for(i=0;i<n;i++){
        scanf("%d", &arr[i]);
    }
    for(i=1;i<=m;i++){ //앞에서부터 마지막까지 가면서 교환하는 작업을 m번 반복합니다.
        for(j=0;j<n-i;j++){
            if(arr[j]>arr[j+1]){
                SWAP(arr[j], arr[j+1]);
            }
        }
        for(k=0;k<n;k++){ //작업을 1회 시행할 때 마다 진행 상황을 출력합니다. 따라서 마지막에 출력된 것이 결과입니다.
            printf("%d ", arr[k]);
        }
        printf("\n");
    }
    return 0;
}
