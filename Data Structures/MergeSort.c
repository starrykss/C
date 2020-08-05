// Merge Sort
#include <stdio.h>

#define N 8

int temp[N];  // 정렬된 데이터 저장 배열

// 병합 정렬 함수
void merge(int ary[], int m, int middle, int n) {
    int i, j, k, t;

    i = m;  // 첫번째 배열
    j = middle + 1; // 중간의 뒤 배열
    k = m; // 첫번째 배열

    while (i <= middle && j <= n) {
        if (ary[i] <= ary[j]) { // 앞의 값이 작을 때 비교
            temp[k] = ary[i];  // 정렬된 배열 저장
            i++;
        }
        else { // 앞의 값이 클 때 비교
            temp[k] = ary[j];
            j++;    // 다음 변수 비교를 위한 증가
        }
        k++;  // 현재 위치를 알고자 하는 증가
    }
    
    if (i > middle) {
        for (t = j; t <= n; t++, k++) {
            temp[k] = ary[t];
        }
    }
    else {
        for (t = i; t <= middle; t++, k++) {
            temp[k] = ary[t];
        }
    }

    for (t = m; t <= n; t++) {
        ary[t] = temp[t];
    }
}

// 분할 함수
void MergeSort(int ary[], int m, int n) {
    int middle;
    if (m < n) {
        middle = (m + n) / 2;             // 가운데 배열 설정
        MergeSort(ary, m, middle);        // 병합 정렬 함수 호출(왼쪽)   
        MergeSort(ary, middle + 1, n);    // 병합 정렬 함수 호출(오른쪽)    
        merge(ary, m, middle, n);         // 오른쪽 정렬을 위한 함수 호출
    }
}

void main() {
    int data[N] = {69, 10, 30, 2, 16, 8, 31, 22};
    int temp;

    printf("정렬 전 : ");
    for (int i = 0; i < N; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");

    // 병합 정렬 알고리즘
    MergeSort(data, 0, N - 1);

    printf("정렬 후 : ");
    for (int i = 0; i < N; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");
}