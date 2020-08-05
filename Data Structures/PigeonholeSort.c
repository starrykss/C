// Pigeonhole Sort
#include <stdio.h>
#include <stdlib.h>

#define N 8

void PigeonholeSort(int ary[], int n) {
    int i, j, min, max, range, *house;
    
    for (i = 1, min = max = ary[0]; i < n; i++) {
        if (ary[i] < min) min = ary[i];
        if (ary[i] > max) max = ary[i];
    }
    
    range = max - min + 1;
    house = (int *)calloc(sizeof(int), range);
    if (house == NULL) {
        fprintf(stdin, "비둘기집을 만들 공간이 부족합니다. \n");
        return;
    }
    for (i = 0; i < n; i++) house[ary[i] - min]++;
    for (i = j = 0; i < range; i++) {
        while (house[i] > 0) {
            house[i]--;
            ary[j++] = i + min;
        }
    }
    free(house);
}

void main() {
    int data[N] = {69, 10, 30, 2, 16, 8, 31, 22};
    int temp;

    printf("정렬 전 : ");
    for (int i = 0; i < N; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");

    // 비둘기집 정렬 알고리즘
    PigeonholeSort(data, N);

    printf("정렬 후 : ");
    for (int i = 0; i < N; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");
}