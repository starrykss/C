#include <stdio.h>

#define SWAP(x, y, t) ((t)=(x), (x)=(y), (y)=(t))

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

void selection_sort(int list[], int n) {
    int i, j, least, tmp;
    for (i = 0; i < n - 1; i++) {
        least = i;
        for (j = i + 1; j < n; j++) {
            if (list[j] < list[least]) {
                least = j;
            }
        }
        SWAP(list[i], list[least], tmp);
        printStep(list, n, i + 1);
    }
}

void main() {
    int list[8] = {7, 4, 9, 6, 3, 8, 7, 5};
    printArray(list, 8, "Original");
    selection_sort(list, 8);
    printArray(list, 8, "Selection");
}