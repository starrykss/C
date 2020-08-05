#include <stdio.h>
#include <stdlib.h>

typedef struct Student {
    int id;         // 학번
    char name[32];  // 이름
    char dept[32];  // 학과
} Student;
typedef Student Element;

typedef struct LinkedNode {
    Element data;
    struct LinkedNode *link;
} Node;

Node *front = NULL;
Node *rear = NULL;

void error(char *str) {
    fprintf(stderr, "%s\n", str);
    exit(1);
}

int is_empty() { return front == NULL; }
int init_queue() { front = rear = NULL; }

int size() {
    Node *p;
    int count = 0;
    for (p = front; p != NULL; p = p->link) count++;
    
    return count;
}

void enqueue(Element e) {
    Node *p = (Node*)malloc(sizeof(Node));
    p->data = e;
    p->link = NULL;

    if (is_empty()) front = rear = p;  // 공백상태의 삽입
    else {  // 비 공백 상태의 삽입
        rear->link = p;
        rear = p;
    }
}

Element dequeue() {
    Node *p;
    Element e;

    if (is_empty()) {
        error("큐 공백 에러");
    }

    p = front;
    front = front->link;
    if (front == NULL) rear = NULL; // 노드가 하나이면
    e = p->data;;
    free(p);

    return e;
}

Element peek() {
    if (is_empty()) {
        error("큐 공백 에러");
    }

    return front->data;
}

void destroy_queue() {
    while (is_empty() == 0) {
        dequeue();
    }
}

void print_queue(char *msg) {
    Node *p;
    printf("%s[%2d]= ", msg, size());
    for (p = front; p != NULL; p = p->link) {
        printf("%2d ", p->data);
    }
    printf("\n");
}