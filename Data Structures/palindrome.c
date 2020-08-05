#include <stdio.h>
#include <stdlib.h> // exit()
#include <string.h> // strlen()
#include <ctype.h> // tolower()

#define MAX_STACK_SIZE 100

typedef int Element;
typedef struct {
    Element data[MAX_STACK_SIZE];
    int top;
} StackType;

 
void init_stack(StackType *s) { s->top = -1; }
int size(StackType *s) { return s->top + 1; }
int is_empty(StackType *s) { return (s->top == -1); }
int is_full(StackType *s) { return (s->top == MAX_STACK_SIZE - 1); }

void push(StackType *s, Element e) {
    if (is_full(s)) {
        fprintf(stderr, "스택 포화 에러\n");
        exit(1);
    }
    s->data[++(s->top)] = e;
}

Element pop(StackType *s) {
    if (is_empty(s)) {
        fprintf(stderr, "스택 공백 에러\n");
        exit(1);
    }
    return s->data[(s->top)--];
}

Element peek(StackType *s) {
    if (is_empty(s)) {
        fprintf(stderr, "스택 공백 에러\n");
        exit(1);
    }
    return s->data[s->top];
}

void main() {
    char input[MAX_STACK_SIZE];
    StackType origin, cmp;
    int sizeStr = 0, isSame = 0;

    gets(input);

    init_stack(&origin);
    init_stack(&cmp);

    for (int i = 0; i < strlen(input); i++) {
        // 오로지 영문자 혹은 숫자만 스택에 저장 (구두점, 스페이스 제외)
        if ((input[i] >= 'a') && (input[i] <= 'z') || 
            (input[i] >= 'A') && (input[i] <= 'Z') ||
            (input[i] >= '0') && (input[i] <= '9')) {
                push(&origin, tolower(input[i]));  // 소문자로 변환하여 스택에 삽입
            }
        else {
            continue; 
        }
    }

    sizeStr = size(&origin);
    for (int i = 0; i < sizeStr / 2; i++) {
        push(&cmp, pop(&origin));
    }
    for (int i = 0; i < sizeStr / 2; i++) {
        if (pop(&cmp) == pop(&origin)) {
            isSame = 1;
        }
        else {
            isSame = 0;
            break;
        }
    }
    if (isSame == 0) {
        printf("not palindrome. \n");
    }
    else {
        printf("palindrome. \n");
    }
}