// 배열로 구현한 우선순위 큐 프로그램
// : 내림차순으로 자료의 우선순위가 매겨져 큐에 저장됨.

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int front;
    int rear;
    int data[MAX];
} PQType;

// 초기화 함수
void init(PQType *pq) { pq->front = pq->rear = -1; }

// 공백 상태 검출 함수
void is_empty(PQType *pq) {
    if ((pq->front == -1) && (pq->rear == -1)) {
        fprintf(stderr, "Priority Queue is empty.");
        exit(1);
    }
}

// 포화 상태 검출 함수
void is_full(PQType *pq) {
    if (pq->rear >= MAX -1) {
        fprintf(stderr, "Priority Queue is full.");
        exit(1);
    }
}

// 우선순위를 확인하고 요소를 우선순위 큐에 삽입하는 함수
void check(PQType *pq, int data) {
    int i, j;

    for (i = 0; i <= pq->rear; i++) {
        if (data >= pq->data[i]) {
            for (j = pq->rear + 1; j > i; j--) {
                pq->data[j] = pq->data[j - 1];
            }
            pq->data[i] = data;
            return;
        }
    }
    pq->data[i] = data;
}

// 원하는 요소를 우선순위 큐에 삽입하는 함수
void insert(PQType *pq, int data) {
    is_full(pq);
    if ((pq->front == -1) && (pq->rear == -1)) {
        pq->front++;
        pq->rear++;
        pq->data[pq->rear] = data;
        return;
    }
    else {
        check(pq, data);
    }
    pq->rear++;
}

// 원하는 요소를 삭제하는 함수
void delete(PQType *pq, int data) {
    int i;

    is_empty(pq);
    for (i = 0; i <= pq->rear; i++) {
        if (data == pq->data[i]) {
            for (; i < pq->rear; i++) {
                pq->data[i] = pq->data[i + 1];
            }
            pq->data[i] = -99;
            pq->rear--;

            if (pq->rear == -1) pq->front = -1;
            return;
        }
    }
    printf("%d is not found in queue to delete.\n", data);
}

// 가장 우선순위가 높은 요소를 꺼내서 반환하는 함수
int delete_top(PQType *pq) {
    int i, data;

    is_empty(pq);
    data = pq->data[0];
    for (i = 0; i < pq->rear; i++) {
        pq->data[i] = pq->data[i + 1];
    }
    pq->rear--;
    
    return data;
}

// 가장 우선순위가 높은 요소를 삭제하지 않고 반환하는 함수
int find(PQType *pq) {
    is_empty(pq);

    return pq->data[0];
}

// 우선순위 큐의 요소들을 출력하는 함수
void print(PQType *pq) {
    is_empty(pq);
    for(int i = 0; i < pq->rear + 1; i++) {
        printf("%d ", pq->data[i]);
    }
    printf("\n");
}

void main() {
    int n, ch;
    PQType pq;
 
    printf("\n1 - Insert an element into queue");
    printf("\n2 - Delete an element from queue");
    printf("\n3 - Display queue elements");
    printf("\n4 - Remove the highest priority element");
    printf("\n5 - Find the highest priority element");
    printf("\n6 - Exit");
    printf("\n");
 
    init(&pq);
 
    while (1) {
        printf("Enter your choice : ");    
        scanf("%d", &ch);
 
        switch (ch) {
        case 1: 
            printf("Enter value to be inserted : ");
            scanf("%d",&n);
            insert(&pq, n);
            break;
        case 2:
            printf("Enter value to delete : ");
            scanf("%d",&n);
            delete(&pq, n);
            break;
        case 3: 
            print(&pq);
            break;
        case 4:
            printf("Removing the highest priority element...\n");
            delete_top(&pq);
            break;
        case 5:
            printf("The highest priority element is %d\n", find(&pq));
            break;
        case 6: 
            exit(0);
        default: 
            printf("Choice is incorrect, Enter a correct choice");
        }
    }
}


/*
void main() {
    PQType pq;

    init(&pq);

    insert(&pq, 2);
    insert(&pq, 12);
    insert(&pq, 5);
    insert(&pq, 7);
    insert(&pq, 10);

    print(&pq);
    printf("[3, 5 삭제]\n");
    delete(&pq, 3);
    delete(&pq, 5);

    print(&pq);
    printf("우선순위 가장 높은 요소 삭제 x 2\n");
    delete_top(&pq);
    delete_top(&pq);

    print(&pq);
}
*/