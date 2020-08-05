#include <stdio.h>
#include <malloc.h>
 
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
void init(QueueType *queue) { 
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
 
// peek 함수
element peek(QueueType *queue) {
    if (is_empty(queue)) {
        error("큐가 비어있습니다.");
    } 
    else {
        return queue->front->item;        // 데이터 반환 
    }
}
 
// 연결된 큐 테스트 함수
void main() {
    QueueType q;
 
    init(&q);
    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    printf("dequeue()=%d\n", dequeue(&q));
    printf("dequeue()=%d\n", dequeue(&q));
    printf("dequeue()=%d\n", dequeue(&q));
}