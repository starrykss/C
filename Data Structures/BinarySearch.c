// 순환 호출을 이용한 이진 탐색 프로그램

#include <stdio.h>

#define LIST_SIZE 9

int count = 0;

// 순환 호출을 이용한 이진 탐색 알고리즘
int binarySearch(int list[], int key, int low, int high) {
    int middle;

    if (low <= high) { // 아직 숫자들이 남아 있으면
        middle = (low + high) / 2;

        printf("middle : %d\n", middle);

        if (key == list[middle]) {  // 탐색 성공
            count++;
            return middle;
        }
        else if (key < list[middle]) { // 왼쪽 부분 리스트 탐색
            count++;
            return binarySearch(list, key, low, middle - 1);
        }
        else {  // 오른쪽 부분 리스트 탐색
            count++;
            return binarySearch(list, key, middle + 1, high);
        }
    }
    return -1; // 탐색 실패
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
    
    ret = binarySearch(list, number, 0, LIST_SIZE - 1);
    
    if (ret >= 0) {
        printf("탐색 성공: 숫자(%d) 위치=%d\n", number, ret);
    }
    else {
        printf("숫자(%d) 탐색 실패\n", number);
    }

    printf("비교 횟수 : %d \n", count);
}