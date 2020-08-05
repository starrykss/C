// Radix Sort
#include <stdio.h>
#include <stdlib.h>

#define N 8
#define BUCKETS 10  // 10진법
#define DIGITS 2    // 숫자의 자릿수
 
typedef int element;    // 요소의 타입
typedef struct QueueNode { // 큐의 노드 타입
    element item;
    struct QueueNode *link;
} QueueNode;
 
typedef struct {        // 큐 ADT 구현
    QueueNode *front, *rear;
} QueueType;
 
// 오류 함수
void error(char *message) {
    fprintf(stderr, "%s\n", message);
    exit(1);
}
 
// 초기화 함수
void init_queue(QueueType *queue) { 
    queue->front = queue->rear = NULL; 
}
 
// 공백 상태 검출 함수
int is_empty(QueueType *queue) { 
    return (queue->front == NULL); 
}
 
// 삽입 함수
void enqueue(QueueType *queue, element item) {
    QueueNode *temp = (QueueNode *)malloc(sizeof(QueueNode));
    if (temp == NULL) {
        error("메모리를 할당할 수 없습니다.");
    }
    else {
        temp->item = item;        // 데이터 저장
        temp->link = NULL;        // 링크 필드를 NULL로 설정
        if (is_empty(queue)) {            // 큐가 공백이라면
            queue->front = temp;
            queue->rear = temp;
        }
        else {        // 큐가 공백이 아니면
            queue->rear->link = temp;    // 순서가 중요
            queue->rear = temp;
        }
    }
}
 
// 삭제 함수
element dequeue(QueueType *queue) {
    QueueNode *temp = queue->front;
    element item;
    if (is_empty(queue)) {        // 공백 상태
        error("큐가 비어 있습니다.");
    }
    else {
        item = temp->item;        // 데이터를 꺼낸다.    
        queue->front = queue->front->link;    // front를 다음 노드를 가리키도록 한다.                                                 
        if (queue->front == NULL) {        // 공백 상태
            queue->rear = NULL;
        }
        free(temp);        // 노드 메모리 해제
        return item;        // 데이터 반환
    }
}

// 기수 정렬 함수
void RadixSort(int ary[], int n) {
    int i, j, k;
    int factor = 1;  // 증가량 : 1, 10, 100, ...
    QueueType Q[BUCKETS];

    // 큐 초기화
    for (i = 0; i < BUCKETS; i++) {
        init_queue(&Q[i]);
    }

    for (k = 0; k < DIGITS; k++) {
        for (i = 0; i < n; i++) {
            enqueue(&Q[(ary[i] / factor) % 10], ary[i]); // 자리수에 따라 큐에 삽입
        }
        for (i = j = 0; i < BUCKETS; i++) {
            while(!is_empty(&Q[i])) {   // 모든 큐가 NULL일 때까지
                ary[j++] = dequeue(&Q[i]); // 정렬된 데이터 삽입
            }
        }
        factor *= 10; // 다음 자릿수로 변경
    }
}

void main() {
    int data[N] = {69, 10, 30, 2, 16, 8, 31, 22};
    int temp;

    printf("정렬 전 : ");
    for (int i = 0; i < N; i++) {
        printf("%d ", data[i]);
    }
    printf("\n\n");

    // 퀵 정렬 알고리즘
    RadixSort(data, N);

    printf("정렬 후 : ");
    for (int i = 0; i < N; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");
}