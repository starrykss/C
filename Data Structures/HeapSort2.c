#include <stdio.h>

#define N 8

void Swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void MakeMinHeap(int ary[], int start, int count) {
    int node_left, node_right, node_current, node_start, node_index;

    if (count - start < 2) return;
    node_current = start;
    while (node_current >= 0) {
        node_index = node_current;
        node_start = node_current;
        while (node_start*2+1 < count) {
            node_left = node_start * 2 + 1;
            node_right = node_start * 2 + 2;
            node_start = node_left;

            if (node_right < count && ary[node_right] >= ary[node_left]) {
                node_start = node_right;
            }
            if (ary[node_start] > ary[node_index]) {
                Swap(&ary[node_index], &ary[node_start]);
                node_index = node_start;
            }
        }
        --node_current;
    }
}
 
void HeapSort(int ary[], int count) {
    MakeMinHeap(ary, count/2 - 1, count);
    while(count > 0) {
        --count;
        Swap(&ary[0], &ary[count]);
        MakeMinHeap(ary, 0, count);
    }
}

void main() {
    int data[N] = {38, 49, 53, 55, 71, 72, 82, 92};
    int temp;

    printf("정렬 전 : ");
    for (int i = 0; i < N; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");

    // 히프 정렬 알고리즘
    HeapSort(data, N);

    printf("정렬 후 : ");
    for (int i = 0; i < N; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");
}