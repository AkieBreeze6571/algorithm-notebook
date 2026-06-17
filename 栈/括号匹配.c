
typedef struct Stack {
    char a[10001];
    int top;
} Stack;

// 入栈
void push(Stack* s, char x) {
    s->top++;
    s->a[s->top] = x;
}

// 判空
bool isEmpty(Stack* s) {
    return s->top == -1;
}

// 出栈并匹配
bool match(Stack* s, char x) {
    // 如果栈空，说明没有左括号可以匹配
    if (isEmpty(s)) {
        return false;
    }

    // 栈顶元素和当前右括号对应的数字不一致
    if (s->a[s->top] != x) {
        return false;
    }

    // 匹配成功，出栈
    s->top--;
    return true;
}

bool isValid(char* s) {
    Stack st;
    st.top = -1;

    int i = 0;

    while (s[i] != '\0') {
        if (s[i] == '(') {
            push(&st, '1');
        } else if (s[i] == '[') {
            push(&st, '2');
        } else if (s[i] == '{') {
            push(&st, '3');
        } else if (s[i] == ')') {
            if (!match(&st, '1')) {
                return false;
            }
        } else if (s[i] == ']') {
            if (!match(&st, '2')) {
                return false;
            }
        } else if (s[i] == '}') {
            if (!match(&st, '3')) {
                return false;
            }
        }

        i++;
    }

    // 最后栈必须为空
    return isEmpty(&st);
}