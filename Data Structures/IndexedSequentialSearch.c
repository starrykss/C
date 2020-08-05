// 색인 순차 탐색 프로그램

#include <stdio.h>

#define LIST_SIZE 9
#define INDEX_SIZE 3

int count = 0;

// 인덱스 테이블 항목의 구조체
typedef struct {
    int key;    // 키 값   
    int index;  // 키 값의 인덱스
} Index;

// 순차 탐색 알고리즘
int sequentialSearch(int list[], int key, int low, int high) {
    for (int i = low; i <= high; i++) {
        count++;
        if (list[i] == key) return i; // index 반환
    }
    return -1;
}

// 색인 순차 탐색 알고리즘
int indexedSearch(int list[], int nList, Index *tbl, int nTbl, int key) {
    int i;

    if (key < list[0] || key > list[nList - 1]) { // 키 값이 리스트 범위 밖
        return -1;  // 탐색 실패
    }
    for (i = 0; i < nTbl - 1; i++) {    // 인덱스 테이블 조사
        if (tbl[i].key <= key && tbl[i + 1].key >= key) {
            return sequentialSearch(list, key, tbl[i].index, tbl[i + 1].index);
        }
    }
    return sequentialSearch(list, key, tbl[nTbl - 1].index, nList);
}

void main() {
    int list[LIST_SIZE] = {3, 9, 15, 22, 31, 55, 67, 88, 91};
    Index index[INDEX_SIZE] = { {3, 0}, {15, 3}, {67, 6} };
    int number, ret;

    printf("LIST : ");
    for (int i = 0; i < LIST_SIZE; i++) {
        printf("%d ", list[i]);
    }
    printf("\n");

    printf("탐색할 숫자 입력 : ");
    scanf("%d", &number);
    
    ret = indexedSearch(list, LIST_SIZE, index, INDEX_SIZE, number);
    
    if (ret >= 0) {
        printf("탐색 성공: 숫자(%d) 위치=%d\n", number, ret);
    }
    else {
        printf("숫자(%d) 탐색 실패\n", number);
    }

    printf("비교 횟수 : %d \n", count);
}