// 후위 표기식 계산
 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100
typedef char element;
typedef struct {
    element stack[MAX_STACK_SIZE];
    int top;
} StackType;
 
// 스택 초기화 함수
void init(StackType *s) {
    s->top = -1;
}
 
// 공백 상태 검출 함수
int is_empty(StackType *s) {
    return (s->top == -1);
}
 
int is_full(StackType *s) {
    return (s->top == (MAX_STACK_SIZE - 1));
}
 
// 삽입 함수
void push(StackType *s, element item) {
    if (is_full(s)) {
        fprintf(stderr, "스택 포화 에러\n");
        return;
    }
    else s->stack[++(s->top)] = item;
}
 
// 삭제 함수
element pop(StackType *s) {
    if (is_empty(s)) {
        fprintf(stderr, "스택 공백 에러\n");
        exit(1);
    }
    else return s->stack[(s->top)--];
}
 
// 피크 함수
element peek(StackType *s) {
    if (is_empty(s)) {
        fprintf(stderr, "스택 공백 에러\n");
        exit(1);
    }
    else return s->stack[s->top];
}
 
// 후위 표기 수식 계산 함수
int eval(char exp[]) {
    int op1, op2, value, i = 0;
    int len = strlen(exp);
    char ch;
    StackType s;
    init(&s);
    for (i = 0; i < len; i++) {
        ch = exp[i];
        if (ch != '+' && ch != '-' && ch != '*' && ch != '/') {
            value = ch - '0';        // 입력이 피연산자이면 (실제 숫자로 바꿔주기 위해 필요)
            push(&s, value);
        }
        else {                            // 연산자이면 피연산자를 스택에서 제거
            op2 = pop(&s);
            op1 = pop(&s);
            switch (ch) {            // 연산을 수행하고 스택에 저장
            case '+': push(&s, op1 + op2); break;
            case '-': push(&s, op1 - op2); break;
            case '*': push(&s, op1 * op2); break;
            case '/': push(&s, op1 / op2); break;
            }
        }
    }
    return pop(&s);
}
 
void main() {
    int result;
    printf("후위표기식은 12/4*14/*+\n");
    result = eval("12/4*14/*");
    printf("결과값은 %d\n", result);
}