// Comb Sort
#include <stdio.h>

#define N 8

void CombSort(int ary[], int size) {
    const double shrink = 1.3; // 자료의 개수와 혼잡도에 따라 변경
    int j, tmp, gap = size, swapped = 1;

    while (gap > 1 || swapped) {
        if ((gap /= shrink) < 1) gap =1;
        for (j = swapped = 0; j < size - gap; j++) {
            if (ary[j] <= ary[j + gap]) continue;
            swapped = 1;
            tmp = ary[j];
            ary[j] = ary[j + gap];
            ary[j + gap] = tmp;
        }
    }
}

void main() {
    int data[N] = {69, 10, 30, 2, 16, 8, 31, 22};
    int temp;

    printf("정렬 전 : ");
    for (int i = 0; i < N; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");

    // 빗질 정렬 알고리즘
    CombSort(data, N);

    printf("정렬 후 : ");
    for (int i = 0; i < N; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");
}