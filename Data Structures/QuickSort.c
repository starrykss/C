// Quick Sort
/*
#include <stdio.h>

#define N 8

void QuickSort(int ary[], int begin, int end) {
    int L = begin, R = end;
    int temp;
    int pivot = ary[begin];  // 피봇 위치

    printf("L : %d \tPivot : %d \tR : %d\n", ary[L], pivot, ary[R]);

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
    int data[N] = {71, 49, 92, 55, 38, 82, 72, 53};
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
*/

#include <stdio.h>

#define SWAP(x, y, t) ((t)=(x), (x)=(y), (y)=(t))

void printStep(int list[], int num, int begin) {
    printf("  Step %d =", begin);
    for (int i = 0; i < num; i++) {
        printf("%2d ", list[i]);
    }
    printf("\n");
}

void printArray(int list[], int end, char *content) {
    printf("%s = ", content);
    for (int i = 0; i < end; i++) {
        printf("%2d ", list[i]);
    }
    printf("\n");
}

int partition(int list[], int left, int right) {
    int tmp;
    int low = left + 1;
    int high = right;
    int pivot = list[left];  // 피벗 설정

    printf("pivot : %d", pivot); printStep(list, 8, left);

    while (low <= high) {    // low와 high가 역전되지 않는 한 반복
        while (pivot >= list[low] && low <= right) low++;
        while (pivot <= list[high] && high >= (left + 1)) high--;
        // for (; low <= right && list[low] < pivot; low++);
        // for (; high >= left && list[high] > pivot; high--);
        if (low <= high) {   // 선택된 두 레코드 교환
            SWAP(list[low], list[high], tmp);
            printf("pivot : %d", pivot); printStep(list, 8, left);
        }
    }
    SWAP(list[left], list[high], tmp); // high와 피벗 항목 교환
    printf("pivot : %d", pivot); printStep(list, 8, left);
    
    return high;
}

// 퀵 정렬 : 배열의 left ~ right 항목들을 오름차순으로 정렬하는 함수
void quick_sort(int list[], int left, int right) {
    int q;

    if (left < right) {
        q = partition(list, left, right);
        quick_sort(list, left, q - 1);
        quick_sort(list, q + 1, right);
    }
}

void main() {
    int list[9] = {47, 89, 1, 60, 5, 8, 49, 2, 99};
    printArray(list, 9, "Original ");
    quick_sort(list, 0, 8);
    printArray(list, 9, "QuickSort");
}