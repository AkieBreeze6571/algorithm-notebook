
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

 //先单独完成每一个字符串的拼接发现完整答案后strcpy进原字符串数组里
void backtrack(
    int n,
    int left,
    int right,
    char* path,
    int pos,
    char** result,
    int* returnSize
) {
    // 如果长度达到 2 * n，说明生成了一个完整答案
    if (pos == 2 * n) {
        path[pos] = '\0';

        result[*returnSize] = malloc(sizeof(char) * (2 * n + 1));
        strcpy(result[*returnSize], path);

        (*returnSize)++;
        return;
    }

    // 只要左括号还没用完，就可以继续放 '('
    if (left < n) {
        path[pos] = '(';
        backtrack(n, left + 1, right, path, pos + 1, result, returnSize);
    }

    // 只有右括号数量小于左括号数量时，才能放 ')'
    if (right < left) {
        path[pos] = ')';
        backtrack(n, left, right + 1, path, pos + 1, result, returnSize);
    }
}

char** generateParenthesis(int n, int* returnSize) {
    // n 最大一般不大，先给一个足够的空间
    char** result = malloc(sizeof(char*) * 10000);
    char* path = malloc(sizeof(char) * (2 * n + 1));

    *returnSize = 0;

    backtrack(n, 0, 0, path, 0, result, returnSize);

    free(path);

    return result;
}