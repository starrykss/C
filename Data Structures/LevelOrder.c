// 레벨 순회 프로그램
 
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
 
typedef struct TreeNode {
    int data;
    struct TreeNode *left, *right;
} TreeNode;

typedef int element;    // 요소의 타입

//       15
//    4     20
//  1     16  25
 
TreeNode n1 = { 1, NULL, NULL };
TreeNode n2 = { 4, &n1, NULL };
TreeNode n3 = { 16, NULL, NULL };
TreeNode n4 = { 25, NULL, NULL };
TreeNode n5 = { 20, &n3, &n4 };
TreeNode n6 = { 15, &n2, &n5 };
TreeNode *root = &n6;

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
void init(QueueType *q) {
    q->front = q->rear = NULL;
}
 
// 공백 상태 검출 함수
int is_empty(QueueType *q) {
    return (q->front == NULL);
}
 
// 삽입 함수
void enqueue(QueueType *q, element item) {
    QueueNode *temp = (QueueNode *)malloc(sizeof(QueueNode));
    if (temp == NULL) {
        error("메모리를 할당할 수 없습니다.");
    }
    else {
        temp->item = item;        // 데이터 저장
        temp->link = NULL;        // 링크 필드를 NULL로 설정
        if (is_empty(q)) {            // 큐가 공백이라면
            q->front = temp;
            q->rear = temp;
        }
        else {        // 큐가 공백이 아니면
            q->rear->link = temp;    // 순서가 중요
            q->rear = temp;
        }
    }
}
 
// 삭제 함수
element dequeue(QueueType *q) {
    QueueNode *temp = q->front;
    element item;
    if (is_empty(q)) {        // 공백 상태
        error("큐가 비어 있습니다.");
    }
    else {
        item = temp->item;        // 데이터를 꺼낸다.    
        q->front = q->front->link;    // front를 다음 노드를 가리키도록 한다. 
        if (q->front == NULL) {        // 공백 상태
            q->rear = NULL;
        }
        free(temp);        // 노드 메모리 해제
        return item;        // 데이터 반환
    }
}
 
// peek 함수
element peek(QueueType *q) {
    if (is_empty(q)) {
        error("큐가 비어있습니다.");
    }
    else {
        return q->front->item;        // 데이터 반환
    }
}
 
 
// 레벨 순회
void level_order(TreeNode *ptr) {
    QueueType q;
 
    init(&q);
    if (ptr == NULL) return;
    enqueue(&q, ptr);
    while (!is_empty(&q)) {
        ptr = dequeue(&q);
        printf("[%d]", ptr->data);
        if (ptr->left) enqueue(&q, ptr->left);
        if (ptr->right) enqueue(&q, ptr->right);
    }
}

void main() {
    printf("Level Order : ");
    level_order(root);
}