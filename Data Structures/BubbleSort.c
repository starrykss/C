#include <stdio.h>

#define SWAP(x, y, t) ((t)=(x), (x)=(y), (y)=(t))

void printStep(int list[], int num, int begin) {
    printf("   Step %d =", begin);
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

void bubble_sort(int list[], int n) {
    int i, j, bChanged, tmp;
    for (i = n - 1; i > 0; i--) {
        bChanged = 0;
        for (j = 0; j < i; j++) {
            if (list[j] > list[j + 1]) {
                printStep(list, n, n - i);
                SWAP(list[j], list[j + 1], tmp);
                printStep(list, n, n - i);
                bChanged = 1;
            }
        }
        if (!bChanged) break;
    }
}

void main() {
    int list[8] = {7, 4, 9, 6, 3, 8, 7, 5};
    printArray(list, 8, "Original");
    bubble_sort(list, 8);
    printArray(list, 8, "BubbleSort");
}