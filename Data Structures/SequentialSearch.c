// 순차 탐색 프로그램

#include <stdio.h>

#define LIST_SIZE 16

int count = 0;

// int 배열 list의 순차 탐색
int sequentialSearch(int list[], int key, int low, int high) {
    for (int i = low; i <= high; i++) {
        count++;
        if (list[i] == key) return i; // index 반환
    }
    return -1;
}

void main() {
    int list[LIST_SIZE] = {8, 11, 12, 15, 16, 19, 20, 23, 25, 28, 29, 31, 33, 35, 38, 40};
    int number, ret;
    
    printf("LIST : ");
    for (int i = 0; i < LIST_SIZE; i++) {
        printf("%d ", list[i]);
    }
    printf("\n");

    printf("탐색할 숫자 입력 : ");
    scanf("%d", &number);
    
    ret = sequentialSearch(list, number, 0, LIST_SIZE - 1);
    
    if (ret >= 0) {
        printf("탐색 성공: 숫자(%d) 위치=%d\n", number, ret);
    }
    else {
        printf("숫자(%d) 탐색 실패\n", number);
    }

    printf("비교 횟수 : %d \n", count);
}
