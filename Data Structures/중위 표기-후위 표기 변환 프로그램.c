// 중위 표기 -> 후위 표기 변환 프로그램

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
        if ((c >= '0' && c <= '9')) {
            printf("%c ", c);
        }
        else if (c == '(') {
            push(c);
        }
        else if (c == ')') {
            while (is_empty() == 0) {
                op = pop();
                if (op == '(') break;
                else printf("%c ", op);
            }
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/') {
            while (is_empty() == 0) {
                op = peek();
                if (precedence(c) <= precedence(op)) {
                    printf("%c ", op);
                    pop();
                }
                else break;
            }
            push(c);
        }
    }
    while (is_empty() == 0) {
        printf("%c ", pop());
    }
    printf('\n');
}