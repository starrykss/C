// 정렬된 배열에서의 순차 탐색 프로그램

#include <stdio.h>

#define LIST_SIZE 9

int count = 0;

// 정렬된 배열에서의 순차 탐색 알고리즘
int sorted_sequentialSearch(int list[], int key, int low, int high) {
    int i;

    list[high + 1] = key;
    for (i = low; list[i] != key; i++) count++;  // 키 값을 찾으면 종료
    if (i == (high + 1)) 
        return -1;  // 탐색 실패
    else 
        return i;   // 탐색 성공 
}

void main() {
    int list[LIST_SIZE] = { 3, 9, 15, 22, 31, 55, 67, 88, 91 };
    int number, ret;
    
    printf("LIST : ");
    for (int i = 0; i < LIST_SIZE; i++) {
        printf("%d ", list[i]);
    }
    printf("\n");

    printf("탐색할 숫자 입력 : ");
    scanf("%d", &number);
    
    ret = sorted_sequentialSearch(list, number, 0, LIST_SIZE - 1);
    
    if (ret >= 0) {
        printf("탐색 성공: 숫자(%d) 위치=%d\n", number, ret);
    }
    else {
        printf("숫자(%d) 탐색 실패\n", number);
    }
    printf("비교 횟수 : %d \n", count);
}
