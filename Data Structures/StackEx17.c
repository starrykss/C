#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100

typedef int Element;
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
        printf("%2d ", data[i]);
    }
    printf("\n");
}

void main() {
    init_stack();
    int n = 4096;
    while (n > 0) {
        push(n % 2);
        n /= 2;
    }
    while (!is_empty())
        printf("%d", pop());
}