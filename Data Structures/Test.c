#include <stdio.h>
#include <stdlib.h>  // exit()

#define MAX_ELEMENTS 200  // 최대 히프 크기 + 1
#define HEAP_FULL(n) (n == MAX_ELEMENTS - 1)
#define HEAP_EMPTY(n) (!n)

typedef struct {
    int key;
} element;

typedef struct {
    element heap[MAX_ELEMENTS];
    int size;
} Heap;

// 함수 정의
void insert_max_heap(Heap *hp, element item);
element delete_max_heap (Heap *hp);

// 메인 함수
void main() {
    int count = 10;
    element input[count];
    Heap hp;

    hp.size = 0;
    
    // 사용자로부터 10개의 정수 입력 받기
    // PUSH : 사용자로부터 입력받은 input 배열에 담긴 값을 Heap에 삽입
    for (int i = 0; i < count; i++) {
        scanf("%d", &input[i].key);
        insert_max_heap(&hp, input[i]);  
    }
    
    // 출력하기
    // 사용자로부터 입력 받은 값 출력
    printf("BEFORE : ");
    for (int i = 0; i < count; i++) {
        printf("[%d]", input[i]);
    }
    // POP : Heap 안에서 가장 큰 수부터 출력
    printf("\nAFTER  : ");
    for (int i = 0; i < count; i++) {
        printf("[%d]", delete_max_heap(&hp));
    }
}

// 함수 구현

// 최대 히프에 삽입 
void insert_max_heap(Heap *hp, element item) {
    int i;
    if (HEAP_FULL(hp->size)) {
        fprintf(stderr, "The haep is full. \n");
        exit(1);
    }
    i = ++(hp->size);
    while ((i != 1) && (item.key > hp->heap[i / 2].key)) {
        hp->heap[i] = hp->heap[i / 2];
        i /= 2;
    }
    hp->heap[i] = item; // 새로운 노드 삽입
}


// 최대 히프에서의 삭제 : 가장 큰 값의 원소를 히프에서 삭제
element delete_max_heap (Heap *hp) {
    int parent, child;
    element item, temp;

    if (HEAP_EMPTY(hp->size)) {
        fprintf(stderr, "The heap is empty. \n");
        exit(1);
    }
    // 가장 큰 키값을 저장
    item = hp->heap[1];
    // 히프를 재구성하기 위해 마지막 원소를 이용
    temp = hp->heap[(hp->size)--];
    parent = 1;
    child = 2;
    while (child <= hp->size) {
        // 현 parent의 가장 큰 자식을 탐색
        if ((child < hp->size) && ((hp->heap[child].key) < hp->heap[child + 1].key)) {
            child++;
        }
        if (temp.key >= hp->heap[child].key) {
            break;
        }
        // 아래 단계로 이동
        hp->heap[parent] = hp->heap[child];
        parent = child;
        child *= 2;
    }
    hp->heap[parent] = temp;

    return item;
}