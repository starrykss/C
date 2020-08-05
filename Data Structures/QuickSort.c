// Quick Sort
#include <stdio.h>

#define N 8

void QuickSort(int ary[], int begin, int end) {
    int L = begin, R = end;
    int temp;
    int pivot = ary[(begin + end) / 2];  // 피봇 위치(중앙)

    printf("L : %d \tPivot : %d \tR : %d\n", ary[L], ary[(begin + end) / 2], ary[R]);

    // 피봇을 기준으로 좌, 우 분할(Partition)
    while (L <= R) {
        while (ary[L] < pivot) L++;
        while (ary[R] > pivot) R--;
        // L, R 모두 최대 pivot 위치까지 이동

        if (L <= R) {
            if (L != R) {
                temp = ary[L];
                ary[L] = ary[R];
                ary[R] = temp;
            }
            L++; R--;

            for (int i = 0; i < N; i++) {
                printf("%d ", ary[i]);
            }
            printf("\n");
        }
    }
    printf("\n");

    // 재귀함수 호출
    if (begin < R) QuickSort(ary, begin, R);
    if (L < end) QuickSort(ary, L, end);
}

void main() {
    int data[N] = {69, 10, 30, 2, 16, 8, 31, 22};
    int temp;

    printf("정렬 전 : ");
    for (int i = 0; i < N; i++) {
        printf("%d ", data[i]);
    }
    printf("\n\n");

    // 퀵 정렬 알고리즘
    QuickSort(data, 0, N - 1);

    printf("정렬 후 : ");
    for (int i = 0; i < N; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");
}