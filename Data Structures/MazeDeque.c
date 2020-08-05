#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100
#define MAZE_SIZE 6

typedef struct {
    int x;
    int y;
} Location2D;
typedef Location2D Element;

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

char map[MAZE_SIZE][MAZE_SIZE] = {
    {'1','1','1','1','1','1'},
    {'e','0','1','0','0','1'},
    {'1','0','0','0','1','1'},
    {'1','0','1','0','0','x'},
    {'1','1','1','1','1','1'},
};  // e : 시작, x : 종료

Location2D getLocation2D(int x, int y) {
    Location2D p;
    p.x = x;
    p.y = y;
    
    return p;
}

int is_valid(int x, int y) {
    if (x < 0 || y < 0 || x >= MAZE_SIZE || y >= MAZE_SIZE) return 0;
    else return map[x][y] == '0' || map[x][y] == 'x';
}

int DFS() {
    int x, y;
    Location2D here;
    QueueType dq;

    init_deque(&dq);
    add_rear(&dq, getLocation2D(1, 0));
    printf("DFS: ");
    while (is_empty(&dq) == 0) {
        here = delete_rear(&dq);
        printf("(%2d,%2d)", here.x, here.y);
        x = here.x;
        y = here.y;
        if (map[x][y] == 'x') return 1;
        else {
            map[x][y] = '.';
            if (is_valid(x, y)) add_rear(&dq, getLocation2D(x-1, y));       // 상
            if (is_valid(x + 1, y)) add_rear(&dq, getLocation2D(x + 1, y)); // 하
            if (is_valid(x, y - 1)) add_rear(&dq, getLocation2D(x, y - 1)); // 좌
            if (is_valid(x, y + 1)) add_rear(&dq, getLocation2D(x, y + 1)); // 우
        }
    }
    return 0;
}

int BFS() {
    int x, y;
    Location2D here;
    QueueType dq;

    init_deque(&dq);
    add_rear(&dq, getLocation2D(1, 0));
    printf("BFS: ");
    while (is_empty(&dq) == 0) {
        here = delete_front(&dq);
        printf("(%2d,%2d)", here.x, here.y);
        x = here.x;
        y = here.y;
        if (map[x][y] == 'x') return 1;
        else {
            map[x][y] = '.';
            if (is_valid(x, y)) add_rear(&dq, getLocation2D(x-1, y));       // 상
            if (is_valid(x + 1, y)) add_rear(&dq, getLocation2D(x + 1, y)); // 하
            if (is_valid(x, y - 1)) add_rear(&dq, getLocation2D(x, y - 1)); // 좌
            if (is_valid(x, y + 1)) add_rear(&dq, getLocation2D(x, y + 1)); // 우
        }
    }
    return 0;
}


void main() {
    printf("->%s\n", DFS() ? "성공" : "실패");  // DFS 이용
	// printf("->%s\n", BFS() ? "성공" : "실패");  // BFS 이용
}