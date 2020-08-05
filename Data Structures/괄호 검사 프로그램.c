// 괄호 검사 프로그램

int check_matching(char expr[]) {
    int i = 0, prev;
    char ch;

    init_stack();
    while (expr[i] != '\0') {
        ch = expr[u++];
        if (ch == '[' || ch == '(' || ch == '{') 
            push(ch);
        else if (ch == ']' || ch == ')' || ch == '}') {
            if(is_empty()) {
                return 2;   // 조건 2 위반
            }
            prev = pop();
            if ((ch == ']' && prev != '[')
                || (ch == ')' && prev != '(')
                || (ch == '}' && prev != '{')) {
                    return 3;  // 조건 3 위반
                }
        }
    }
    if (is_empty() == 0) return 1;   // 조건 1 위반
    return 0;   // 괄호 정상
}