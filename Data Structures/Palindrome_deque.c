#include <stdio.h>
#include <stdlib.h> // exit()
#include <string.h> // strlen()
#include <ctype.h> // tolower()

#define MAX_QUEUE_SIZE 100
#define Element int

typedef struct {
    int front;
    int rear;
    Element data[MAX_QUEUE_SIZE];
} QueueType;

// QUEUE
void init_queue(QueueType *queue) { queue->front = queue->rear = 0; }
int is_empty(QueueType *queue) { return queue->front == queue->rear; }
int is_full(QueueType *queue) { return ((queue->rear + 1) % MAX_QUEUE_SIZE == queue->front); }
int size(QueueType *queue) { return ((queue->rear - queue->front + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE); }

void enqueue(QueueType *queue, Element val) {
    if (is_full(queue)) {
        fprintf(stderr, "큐 포화 에러");
        exit(1);
    }
    queue->rear = (queue->rear + 1) % MAX_QUEUE_SIZE;
    queue->data[queue->rear] = val;
}

Element dequeue(QueueType *queue) {
    if (is_empty(queue)) {
        fprintf(stderr, "큐 공백 에러");
        exit(1);
    }
    queue->front = (queue->front + 1) % MAX_QUEUE_SIZE;
    return queue->data[queue->front];
}

Element peek(QueueType *queue) {
    if (is_empty(queue)) {
        fprintf(stderr, "큐 공백 에러");
        exit(1);
    }
    return queue->data[(queue->front + 1) % MAX_QUEUE_SIZE];
}

void print_queue(QueueType *queue, char msg[]) {
    int i, maxi = queue->rear;
    if (queue->front >= queue->rear) maxi += MAX_QUEUE_SIZE;
    printf("%s[%2d]= ", msg, size(queue));
    for (i = queue->front + 1; i <= maxi; i++) {
        printf("%2c ", queue->data[i % MAX_QUEUE_SIZE]);
    }
    printf("\n");
}

// DEQUE
void init_deque(QueueType *queue) { init_queue(queue); }
void add_rear(QueueType *queue, Element val) { enqueue(queue, val); }
Element delete_front(QueueType *queue) { return dequeue(queue); }
Element get_front(QueueType *queue) { return peek(queue); }

void add_front(QueueType *deque, Element val) {
    if (is_full(deque)) {
        fprintf(stderr, "덱 포화 에러");
        exit(1);
    }
    deque->data[deque->front] = val;
    deque->front = (deque->front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
}

Element delete_rear(QueueType *deque) {
    Element ret;
    if (is_empty(deque)) {
        fprintf(stderr, "덱 공백 에러");
        exit(1);
    }
    ret = deque->data[deque->rear];
    deque->rear = (deque->rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
    return ret;
}

Element get_rear(QueueType *deque) {
    if (is_empty(deque)) {
        fprintf(stderr, "덱 공백 에러");
        exit(1);
    }
    return deque->data[deque->rear];
}

Element palindrome(QueueType *deque) {
    int isSame = 0;

    for (int i = 0; i < size(deque); i++) {
        if (get_front(deque) == get_rear(deque)) {
            isSame = 1;
            deque->front = deque->front + 1;
            deque->rear = deque->rear - 1;
        }
        else {
            isSame = 0;
            break;
        }
    }
    return isSame;
}

void main() {
    char input[MAX_QUEUE_SIZE], temp;
    QueueType origin, cmp;

    gets(input);

    init_deque(&origin);

    for (int i = 0; i < strlen(input); i++) {
        // 오로지 영문자 혹은 숫자만 스택에 저장 (구두점, 스페이스 제외)
        if ((input[i] >= 'a') && (input[i] <= 'z') || 
            (input[i] >= 'A') && (input[i] <= 'Z') ||
            (input[i] >= '0') && (input[i] <= '9')) {
                add_rear(&origin, tolower(input[i]));  // 소문자로 변환하여 덱에 삽입
            }
        else {
            continue; 
        }
    }

    if (palindrome(&origin)) {
        printf("palindrome. \n");
    }
    else {
        printf("not palindrome. \n");
    }
}