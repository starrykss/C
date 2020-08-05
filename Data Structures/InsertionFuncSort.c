#include <stdio.h>

int ascend(int x, int y) { return y - x; }
int descend(int x, int y) { return x - y; }

void printStep(int list[], int num, int begin) {
    printf("  Step %d =", begin);
    for (int i = 0; i < num; i++) {
        printf("%2d", list[i]);
    }
    printf("\n");
}

void printArray(int list[], int end, char *content) {
    printf("%s = ", content);
    for (int i = 0; i < end; i++) {
        printf("%2d", list[i]);
    }
    printf("\n");
}

void insertion_sort_fn(int list[], int n, int (*f)(int, int)) {
    int i, j, key;
    for (i = 1; i < n; i++) {
        key = list[i];
        for (j = i - 1; j >= 0 && (f(list[j], key) < 0); j--) {
            list[j + 1] = list[j];  // 레코드의 오른쪽 이동
        }
        list[j + 1] = key;
        printStep(list, n, i);
    }
}

void main() {
    int list[9] = {5, 3, 8, 4, 9, 1, 6, 2, 7};
    printArray(list, 9, "Original");
    insertion_sort_fn(list, 9, descend); // 내림차순 선택 정렬
    printArray(list, 9, "Insertion(Descending)");
    insertion_sort_fn(list, 9, ascend); // 오름차순 선택 정렬
    printArray(list, 9, "Insertion(Ascending)");
}