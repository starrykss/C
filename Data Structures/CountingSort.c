// Counting Sort
#include <stdio.h>
#include <stdlib.h>

#define N 8

void CountingSort(int ary[], int size) {
    // 최대값 찾기
    int max = ary[0];
    for (int i = 0; i < size; i++) {
        if (ary[i] > max) {
            max = ary[i];
        }
    }

    // 동적 할당
    int *count = (int*)malloc(sizeof(int) * max);
    int *output = (int*)malloc(sizeof(int) * max);

    // count 배열의 원소를 0으로 초기화
    for (int i = 0; i <= max; ++i) {
        count[i] = 0;
    }

    // 원소 개수 쌓기
    for (int i = 0; i < size; i++) {
        count[ary[i]]++;
    }

    // 누적합 구하기
    for (int i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }

    // Find the index of each element of the original array in count array, and
    // place the elements in output array
    for (int i = size - 1; i >= 0; i--) {
        output[count[ary[i]] - 1] = ary[i];
        count[ary[i]]--;
    }

    for (int i = 0; i < size; i++) {
        ary[i] = output[i];
    }

    free(count);
    free(output);
}

void main() {
    int data[N] = {69, 10, 30, 2, 16, 8, 31, 22};
    int temp;

    printf("정렬 전 : ");
    for (int i = 0; i < N; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");

    // 계수 정렬 알고리즘
    CountingSort(data, N);

    printf("정렬 후 : ");
    for (int i = 0; i < N; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");
}