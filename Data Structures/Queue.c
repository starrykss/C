#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100
#define Element int

typedef struct {
    int front;
    int rear;
    Element data[MAX_QUEUE_SIZE];
} QueueType;

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

void main() {
    int i;
    QueueType q;

    init_queue(&q);
    for (i = 1; i < 10; i++) {
        enqueue(&q, i);
    }
    print_queue(&q, "선형큐 enqueue 9회");
    printf("\tdequeue() --> %d\n", dequeue(&q));
    printf("\tdequeue() --> %d\n", dequeue(&q));
    printf("\tdequeue() --> %d\n", dequeue(&q));
    print_queue(&q, "선형큐 dequeue 3회");
}