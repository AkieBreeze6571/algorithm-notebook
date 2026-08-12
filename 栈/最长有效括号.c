int longestValidParentheses(char* s) {
    int stack[30001];
    int top = 0;
    int i = 0;
    int max = 0;

    stack[0] = -1;

    while (s[i] != '\0') {

        if (s[i] == '(') {
            top++;
            stack[top] = i;
        } 
        else {
            top--;

            if (top < 0) {
                top = 0;
                stack[top] = i;
            } 
            else {
                if (i - stack[top] > max) {
                    max = i - stack[top];
                }
            }
        }

        i++;
    }

    return max;
}