#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100
#define MAZE_SIZE 6

typedef struct {
    int x;
    int y;
} Location2D;
typedef Location2D Element;

Element data[MAX_QUEUE_SIZE];
int front;
int rear;


void error(char *str) {
    fprintf(stderr, "%s\n", str);
    exit(1);
}

// QUEUE
void init_queue() { front = rear = 0; }
int is_empty() { return front == rear; }
int is_full() { return ((rear + 1) % MAX_QUEUE_SIZE == front); }
int size() { return ((rear - front + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE); }

void enqueue(Element val) {
    if (is_full()) {
        fprintf(stderr, "큐 포화 에러");
        exit(1);
    }
    rear = (rear + 1) % MAX_QUEUE_SIZE;
    data[rear] = val;
}

Element dequeue() {
    if (is_empty()) {
        fprintf(stderr, "큐 공백 에러");
        exit(1);
    }
    front = (front + 1) % MAX_QUEUE_SIZE;
    return data[front];
}

Element peek() {
    if (is_empty()) {
        fprintf(stderr, "큐 공백 에러");
        exit(1);
    }
    return data[(front + 1) % MAX_QUEUE_SIZE];
}

void print_queue(char msg[]) {
    int i, maxi = rear;
    if (front >= rear) maxi += MAX_QUEUE_SIZE;
    printf("%s[%2d]= ", msg, size());
    for (i = front + 1; i <= maxi; i++) {
        printf("%2d ", data[i % MAX_QUEUE_SIZE]);
    }
    printf("\n");
}


// DEQUE
void init_deque() { init_queue(); }
void add_rear(Element val) { enqueue(val); }
Element delete_front() { return dequeue(); }
Element get_front() { return peek(); }

void add_front(Element val) {
    if (is_full()) {
        fprintf(stderr, "덱 포화 에러");
        exit(1);
    }
    data[front] = val;
    front = (front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
}

Element delete_rear() {
    Element ret;
    if (is_empty()) {
        fprintf(stderr, "덱 공백 에러");
        exit(1);
    }
    ret = data[rear];
    rear = (rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
    return ret;
}

Element get_rear() {
    if (is_empty()) {
        fprintf(stderr, "덱 공백 에러");
        exit(1);
    }
    return data[rear];
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

    init_deque();
    add_rear(getLocation2D(1, 0));
    printf("DFS: ");
    while (is_empty() == 0) {
        here = delete_rear();
        printf("(%2d,%2d)", here.x, here.y);
        x = here.x;
        y = here.y;
        if (map[x][y] == 'x') return 1;
        else {
            map[x][y] = '.';
            if (is_valid(x, y)) add_rear(getLocation2D(x-1, y));       // 상
            if (is_valid(x + 1, y)) add_rear(getLocation2D(x + 1, y)); // 하
            if (is_valid(x, y - 1)) add_rear(getLocation2D(x, y - 1)); // 좌
            if (is_valid(x, y + 1)) add_rear(getLocation2D(x, y + 1)); // 우
        }
    }
    return 0;
}

int BFS() {
    int x, y;
    Location2D here;

    init_deque();
    add_rear(getLocation2D(1, 0));
    printf("BFS: ");
    while (is_empty() == 0) {
        here = delete_front();
        printf("(%2d,%2d)", here.x, here.y);
        x = here.x;
        y = here.y;
        if (map[x][y] == 'x') return 1;
        else {
            map[x][y] = '.';
            if (is_valid(x, y)) add_rear(getLocation2D(x-1, y));       // 상
            if (is_valid(x + 1, y)) add_rear(getLocation2D(x + 1, y)); // 하
            if (is_valid(x, y - 1)) add_rear(getLocation2D(x, y - 1)); // 좌
            if (is_valid(x, y + 1)) add_rear(getLocation2D(x, y + 1)); // 우
        }
    }
    return 0;
}


void main() {
    printf("->%s\n", DFS() ? "성공" : "실패");  // DFS 이용
	//printf("->%s\n", BFS() ? "성공" : "실패");// BFS 이용
}