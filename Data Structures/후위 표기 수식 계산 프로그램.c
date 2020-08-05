// 후위 표기 수식 계산 프로그램
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

double calc_postfix(char expr[]) {
    char c;
    int i = 0;
    double val, val1, val2;

    init_stack();
    while (expr[i] != '\0') {
        c = expr[i++];
        if (c >= '0' && c <= '9') {
            val = c - '0';  // char -> int
            push(val);
        }
        else if ((c == '+') || (c == '-') || (c == '*') || (c == '/')) {
                     val2 = pop();
                     val1 = pop();
                     switch (c) {
                         case '+': push(val1 + val2); break;
                         case '-': push(val1 - val2); break;
                         case '*': push(val1 * val2); break;
                         case '/': push(val1 / val2); break;
                     }
                 }
    }
    return pop();
}

void main() {
    char expr[80];
    gets(expr);
    printf("수식: %s = %lf\n", expr, calc_postfix(expr));
    
    // char expr[2][80] = { "8 2 / 3 - 3 2 * +", "1 2 / 4 * 1 4 / *"}; // 교재 내용
    // printf("수식: %s = %lf\n", expr[0], calc_postfix(expr[0]));
    // printf("수식: %s = %lf\n", expr[1], calc_postfix(expr[1]));
}