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


static int precedence(char op) {
    switch (op) {
        case '(': case ')': return 0;
        case '+': case '-': return 1;
        case '*': case '/': return 2;
    }
    return -1;
}

void infix_to_postfix(char expr[]) {
    int i = 0;
    char c, op;

    init_stack();
    while (expr[i] != '\0') {
        c = expr[i++];
        if ((c >= '1' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            printf("%c", c);
        }
        else if (c == '(') {
            push(c);
        }
        else if (c == ')') {
            while (is_empty() == 0) {
                op = pop();
                if (op == '(') break;
                else printf("%c", op);
            }
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/') {
            while (is_empty() == 0) {
                op = peek();
                if (precedence(c) <= precedence(op)) {
                    printf("%c", op);
                    pop();
                }
                else break;
            }
            push(c);
        }
    }
    while (is_empty() == 0) {
        printf("%c", pop());
    }
    printf("\n");
}

void main() {
    char expr[80];
    gets(expr);
    printf("Infix Expression: %s ==> Postfix Expression: ", expr);
    infix_to_postfix(expr);

    /* 교재 예시
    char expr[2][80] = {"8/2-3+(3*2)", "1/2*4*(1/4)"};
    printf("Infix Expression: %s ==> Postfix Expression:", expr[0]);
    infix_to_postfix(expr[0]);
    printf("Infix Expression: %s ==> Postfix Expression:", expr[1]);
    infix_to_postfix(expr[1]);
    */
}