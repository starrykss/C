// Insertion Sort
#include <stdio.h>

#define N 8

void InsertionSort(int ary[], int size) {
    int key;
    int j;  // 랜덤 값
    
    for (int i = 0; i < size - 1; i++) {
        key = ary[i + 1];
        for (j = i; j > -1; j--) {  
            if (ary[j] > key) { 
                ary[j + 1] = ary[j];
            }
            else {
                break;
            }
        }
        ary[j + 1] = key;
    }
}

void main() {
    int data[N] = {69, 10, 30, 2, 16, 8, 31, 22};

    printf("정렬 전 : ");
    for (int i = 0; i < N; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");

    // 삽입 정렬 알고리즘
    InsertionSort(data, N);

    printf("정렬 후 : ");
    for (int i = 0; i < N; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");
}