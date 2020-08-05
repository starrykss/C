// Table Sort
#include <stdio.h>
#include <stdlib.h>

#define N 8

void TableSort(int a[], int n, int t[]) {
    int i, current, next;
    __INT32_C temp;
    for (i = 1; i < n; i++) {
        if (t[i] != i) {
            temp = a[i];
            current = i;
            do {
                next = t[current]; 
                a[current] = a[next];
                t[current] = current;
                current = next;
            } while(t[current] != i)
            a[current] = temp;
            t[current] = current;
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

    // 테이블 정렬 알고리즘
    BucketSort(data, N);

    printf("정렬 후 : ");
    for (int i = 0; i < N; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");
}