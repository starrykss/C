#include <stdio.h>

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

static void sortGapInsertion(int list[], int first, int last, int gap) {
    int i, j, key;
    for (i = first + gap; i <= last; i = i + gap) {
        key = list[i];
        for (j = i - gap; j >= first && key < list[j]; j = j - gap) {
            list[j + gap] = list[j];
        }
        list[j + gap] = key;
    }
}

void shell_sort(int list[], int n) {
    int i, gap, count = 0;
    for (gap = n / 2; gap > 0; gap = gap / 2) {
        if ((gap % 2) == 0) gap++;
        printf("gap : %d   ", gap);
        for (i = 0; i < gap; i++) {
            sortGapInsertion(list, i, n - 1, gap);
        }
        printStep(list, n, ++count);
    }
}

void main() {
    int list[8] = {71, 49, 92, 55, 38, 82, 72, 53};
    printArray(list, 8, "Original");
    shell_sort(list, 8);
    printArray(list, 8, "Shell");
}