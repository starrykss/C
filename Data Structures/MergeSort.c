#include <stdio.h>

#define MAX_SIZE 100

void printArray(int list[], int end, char *content) {
    printf("%s = ", content);
    for (int i = 0; i < end; i++) {
        printf("%2d ", list[i]);
    }
    printf("\n");
}

void printStep(int list[], int num, int begin) {
    printf("  Step %d =", begin);
    for (int i = 0; i < num; i++) {
        printf("%2d ", list[i]);
    }
    printf("\n");
}

static void merge(int list[], int left, int mid, int right) {
    int i, j, k = left, l;          // k : 정렬 될 리스트에 대한 인덱스
    static int sorted[MAX_SIZE];    // 병합된 리스트 저장을 위한 임시 배열
    
    // 분할 정렬된 list의 병합
    for (i = left, j = mid + 1; i <= mid && j <= right;) {
        sorted[k++] = (list[i] <= list[j]) ? list[i++] : list[j++];
    }
    // 한쪽에 남아 있는 레코드의 일괄 복사
    if (i > mid) {
        for (l = j; l <= right; l++, k++) {
            sorted[k] = list[l];
        }
    }
    else {
        for (l = i; l <= mid; l++, k++) {
            sorted[k] = list[l];
        }
    }

    // 배열 sorted[]의 리스트를 배열 list[]로 다시 복사
    for (l = left; l <= right; l++) {
        list[l] = sorted[l];
    }
}

// 병합 정렬 알고리즘을 이용해 int 배열을 오름차순으로 정렬하는 함수
void merge_sort(int list[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;        // 리스트의 균등 분할
        merge_sort(list, left, mid);         // 부분 리스트 정렬
        merge_sort(list, mid + 1, right);    // 부분 리스트 정렬
        merge(list, left, mid, right);       // 병합
    }
}

void main() {
    int list[8] = {71, 49, 92, 55, 38, 82, 72, 53};
    printArray(list, 8, "Original ");
    merge_sort(list, 0, 7);
    printArray(list, 8, "MergeSort");
}