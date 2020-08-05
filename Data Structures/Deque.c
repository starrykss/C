#include <stdio.h>
#include <stdlib.h>

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
        printf("%2d ", queue->data[i % MAX_QUEUE_SIZE]);
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

void main() {
    int i;
    QueueType dq;
    
    init_deque(&dq);

    // HW
    add_front(&dq, 4);
    add_rear(&dq, 8);
    add_rear(&dq, 9);
    add_front(&dq, 5);
    printf("%d\n",get_rear(&dq));
    delete_front(&dq);
    delete_rear(&dq);
    add_rear(&dq, 7);
    printf("%d\n",get_front(&dq));
    printf("%d\n",get_rear(&dq));
    add_rear(&dq, 6);
    delete_front(&dq);
    delete_front(&dq);
    print_queue(&dq, "deque : ");

    /* TEXTBOOK
    for (i = 1; i < 10; i++) {
        if (i % 2) add_front(&dq, i);
        else add_rear(&dq, i);
    }
    

    print_queue(&dq, "원형 덱 삽입 : 홀수-짝수");
    printf("\tdelete_front() --> %d\n", delete_front(&dq));
    printf("\tdelete_rear() --> %d\n", delete_rear(&dq));
    printf("\tdelete_front() --> %d\n", delete_front(&dq));
    print_queue(&dq, "원형 덱 삭제 : 홀수-짝수-홀수");
    */
}