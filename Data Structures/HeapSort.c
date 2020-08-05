// Heap Sort
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
    int data[N] = {69, 10, 30, 2, 16, 8, 31, 22};
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


/*
#include <stdio.h>

#define N 8
#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t))

void MakeMinHeap(int values[], int from, int to) {
    int left, right, go, idx, temp;
    
    if (to - from < 2) {
        return;
    }
    while(from >= 0) {
        idx = from;
        go = from;
        while (go * 2 + 1 < to) {
            left = go * 2 + 1;
            right = go * 2 + 2;
            go = left;
            if (right < to && values[right] <= values[left]) {
                go = right;
            }
            if (values[go] < values[idx]) {
                SWAP(values[idx], values[go], temp);
                idx = go;
            }
            else break;
        }
    --from;
    }
}

// 내림차순 정렬
void HeapSort(int ary[], int c) {
    int temp;
    MakeMinHeap(ary, c/2 - 1, c);
    printf("정렬 후(오름차순) : ");
    while (c > 0) {
        --c;
        printf("%d ", ary[0]); // 오름차순 출력
        SWAP(ary[0], ary[c], temp);
        MakeMinHeap(ary, 0, c);
    }
    printf("\n");
}

void main() {
    int data[N] = {69, 10, 30, 2, 16, 8, 31, 22};
    int temp;

    printf("정렬 전 : ");
    for (int i = 0; i < N; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");

    // 히프 정렬 알고리즘
    HeapSort(data, N);

    printf("정렬 후(내림차순) : ");
    for (int i = 0; i < N; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");
}
*/