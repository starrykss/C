#include <stdio.h>
#include <malloc.h>

#define BUCKETS 10
#define DIGITS 4

typedef int element;
typedef struct QueueNode { 
    element item;
    struct QueueNode *link;
} QueueNode;
 
typedef struct {
    QueueNode *front, *rear;
} QueueType;
 
void error(char *message) {
    fprintf(stderr, "%s\n", message);
    exit(1);
}
 
void init_queue(QueueType *queue) { 
    queue->front = queue->rear = NULL; 
}
 
int is_empty(QueueType *queue) { 
    return (queue->front == NULL); 
}
 
void enqueue(QueueType *queue, element item) {
    QueueNode *temp = (QueueNode *)malloc(sizeof(QueueNode));
    if (temp == NULL) {
        error("메모리를 할당할 수 없습니다.");
    }
    else {
        temp->item = item;
        temp->link = NULL;
        if (is_empty(queue)) {
            queue->front = temp;
            queue->rear = temp;
        }
        else {
            queue->rear->link = temp;
            queue->rear = temp;
        }
    }
}
 
element dequeue(QueueType *queue) {
    QueueNode *temp = queue->front;
    element item;
    if (is_empty(queue)) {
        error("큐가 비어 있습니다.");
    }
    else {
        item = temp->item;    
        queue->front = queue->front->link;  
        if (queue->front == NULL) { 
            queue->rear = NULL;
        }
        free(temp);
        return item;
    }
}
 
element peek(QueueType *queue) {
    if (is_empty(queue)) {
        error("큐가 비어있습니다.");
    } 
    else {
        return queue->front->item;
    }
}

void printArray(int list[], int end, char *content) {
    printf("%s = ", content);
    for (int i = 0; i < end; i++) {
        printf("%4d ", list[i]);
    }
    printf("\n");
}

void radix_sort(int list[], int n) {
    QueueType queues[BUCKETS];
    int factor = 1, i, b, d;

    for (i = 0; i < BUCKETS; i++) {
        init_queue(&queues[i]);
    }

    for (d = 0; d < DIGITS; d++) {
        for (i = 0; i < n; i++) {
            enqueue(&queues[(list[i] / factor) % 10], list[i]);
        }

        for ( b = i = 0; b < BUCKETS; b++) {
            while (!is_empty(&queues[b])) {
                list[i++] = dequeue(&queues[b]);
            }
        }
        factor *= 10;
    }
}

void main() {
    int list[12] = {123, 36, 200, 396, 698, 864, 167, 23, 90, 68, 469, 555};
    printArray(list, 12, "Original ");
    radix_sort(list, 12);
    printArray(list, 12, "RadixSort");
}