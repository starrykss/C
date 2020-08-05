// 구조체를 저장하는 스택

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100

typedef struct Student_t {
    int id;
    char name[32];
    char dept[32];
} Student;

typedef Student Element;
Element data[MAX_STACK_SIZE];

int top;

void init_stack() { top = -1; }
int size() { return top+1; }
int is_empty() { return (top == -1); }
int is_full() { return (top == MAX_STACK_SIZE-1); }

void push(Element e) {
    if (is_full()) {
        fprintf(stderr, "스택 포화 에러\n");
        exit(1);
    }
    data[++top] = e;
}

Element pop() {
    if (is_empty()) {
        fprintf(stderr, "스택 공백 에러\n");
        exit(1);
    }
    return data[top--];
}

Element peek() {
    if (is_empty()) {
        fprintf(stderr, "스택 공백 에러\n");
        exit(1);
    }
    return data[top];
}

void print_stack(char msg[]) {
    int i;
    printf("%s[%2d]= ", msg, size());
    for (i = 0; i < size(); i++) {
        printf("\n\t%-15d %-10s %-20s", data[i].id, data[i].name, data[i].dept);
    }
    printf("\n");
}

Student get_student(int id, char* name, char* dept) {
    Student s;
    s.id = id;
    strcpy(s.name, name);
    strcpy(s.dept, dept);
    return s;
}

void main() {
    init_stack();
    push(get_student(2015130007, "홍길동", "컴퓨터공학과"));
    push(get_student(2015130100, "이순신", "기계공학과"));
    push(get_student(2015130135, "김연아", "체육과"));
    push(get_student(2015130007, "황희", "법학과"));
    print_stack("친구 4명 삽입 후");
    pop();
    print_stack("친구 1명 삭제 후");
}