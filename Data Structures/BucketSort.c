// Bucket Sort
#include <stdio.h>
#include <stdlib.h>

#define N 8

void BucketSort(int ary[], int size) {
    int max;
    
    // 배열에서 최댓값 찾기
    max = ary[0];
    for (int i = 0; i < size; i++) {
        if (ary[i] >= max) {
            max = ary[i];
        }
    }

    int *aux = (int*)malloc(sizeof(int) * (max + 1));

    // initializing the auxiliary array elements to 0
    for (int i = 0; i <= max; i++) {
        aux[i] = 0;
    }

    // filling the auxiliary array with elements of unsorted array
    for (int i = 0; i < size; i++) {
        aux[ary[i]]++;
    }

    // emptying the auxiliary array
    for (int i = 0, j = 0; i <= max; i++) {
        for(; aux[i] > 0; (aux[i])--) {
            ary[j] = i;
            j++;
        }
    }

    free(aux);
}


void main() {
    int data[N] = {69, 10, 30, 2, 16, 8, 31, 22};
    int temp;

    printf("정렬 전 : ");
    for (int i = 0; i < N; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");

    // 버켓 정렬 알고리즘
    BucketSort(data, N);

    printf("정렬 후 : ");
    for (int i = 0; i < N; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");
}