
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** letterCombinations(char* digits, int* returnSize) {
    const char* map[] = {
        "",
        "",
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz"
    };

    int len = strlen(digits);
    int total = 1;
    int i, j;

    if (len == 0) {
        *returnSize = 0;
        return NULL;
    }

    for (i = 0; i < len; i++) {
        total *= strlen(map[digits[i] - '0']);
    }

    char** res = malloc(sizeof(char*) * total);

    for (i = 0; i < total; i++) {
        res[i] = malloc(sizeof(char) * (len + 1));
    }

    for (j = 0; j < total; j++) {
        int div = total;

        for (i = 0; i < len; i++) {
            int digit = digits[i] - '0';
            int letterCount = strlen(map[digit]);

            div /= letterCount;

            res[j][i] = map[digit][(j / div) % letterCount];
        }

        res[j][len] = '\0';
    }

    *returnSize = total;
    return res;
}