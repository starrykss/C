// Shell Sort
#include <stdio.h>

#define N 8

// 데이터를 비교 정렬하는 함수
void intervalSort(int ary[], int begin, int end, int interval) {
    int i, j, item;             
    for(i = begin + interval; i <= end; i = i + interval){     
            item = ary[i];            
            for(j = i - interval; j >= begin && item < ary[j]; j = j - interval) {
                ary[j + interval] = ary[j]; //앞의 원소가 큰 경우
            }
            ary[j + interval] = item; //앞의 원소가 작은 경우
    }
}

// 쉘 정렬 함수
void ShellSort(int ary[], int size) {
        int i, t, interval;
      
        printf("\n");
        interval = size / 2;
        while (interval >= 1) {
                for (i = 0; i < interval; i++) {
                    intervalSort(ary, i, size - 1, interval); 
                }

                printf("interval = %d  >> ", interval);
                for(t = 0; t < size; t++) {
                    printf("%d ", ary[t]);
                }
                printf("\n");

                interval = interval / 2;
        }
        printf("\n");
}

void main() {
    int data[N] = {69, 10, 30, 2, 16, 8, 31, 22};

    printf("정렬 전 : ");
    for (int i = 0; i < N; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");

    // 쉘 정렬 알고리즘
    ShellSort(data, N);

    printf("정렬 후 : ");
    for (int i = 0; i < N; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");
}