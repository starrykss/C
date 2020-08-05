// 보간 탐색 프로그램

#include <stdio.h>

#define LIST_SIZE 9

int count = 0;

// 보간 탐색 알고리즘
int interpolationSearch(int list[], int n, int key) {
    int j, low, high;
    
    low = 0;
    high = n - 1;

    while ((list[low] < key) && (key <= list[high])) {
        j = (int)((float)(key - list[low]) / (list[high] - list[low]) * (high - low)) + low;
        printf("j : %d\n", j);
        if (key > list[j]) {
            count++;
            low = j + 1;
        }
        else if (key < list[j]) {
            count++;
            high = j - 1;
        }
        else {
            count++;
            low = j;
        }
    }
    if (list[low] == key) {
        count++;
        return low; // 탐색 성공
    }
    return -1; // 탐색 실패
}

void main() {
    int list[LIST_SIZE] = {3, 9, 15, 22, 31, 55, 67, 88, 91};
    int number, ret;

    printf("LIST : ");
    for (int i = 0; i < LIST_SIZE; i++) {
        printf("%d ", list[i]);
    }
    printf("\n");

    printf("탐색할 숫자 입력 : ");
    scanf("%d", &number);
    
    ret = interpolationSearch(list, LIST_SIZE, number);
    
    if (ret >= 0) {
        printf("탐색 성공: 숫자(%d) 위치=%d\n", number, ret);
    }
    else {
        printf("숫자(%d) 탐색 실패\n", number);
    }

    printf("비교 횟수 : %d \n", count);
}