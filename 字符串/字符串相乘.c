#include <stdlib.h>
#include <string.h>

char* multiply(char* num1, char* num2) {
    int m;
    int n;
    int* result;
    char* answer;

    int i;
    int j;
    int x;
    int y;
    int mul;
    int sum;

    int start;
    int index;

    m = strlen(num1);
    n = strlen(num2);

    if ((m == 1 && num1[0] == '0') ||
        (n == 1 && num2[0] == '0')) {

        answer = (char*)malloc(sizeof(char) * 2);

        answer[0] = '0';
        answer[1] = '\0';

        return answer;
    }

    result = (int*)calloc(m + n, sizeof(int));

    for (i = m - 1; i >= 0; i--) {

        for (j = n - 1; j >= 0; j--) {

            x = num1[i] - '0';
            y = num2[j] - '0';

            mul = x * y;

            sum = mul + result[i + j + 1];

            result[i + j + 1] = sum % 10;

            result[i + j] += sum / 10;
        }
    }

    /* 去掉最前面的0 */
    start = 0;

    while (start < m + n && result[start] == 0) {
        start++;
    }

    answer =
        (char*)malloc(sizeof(char) * (m + n - start + 1));

    index = 0;

    while (start < m + n) {
        answer[index] = result[start] + '0';

        index++;
        start++;
    }

    answer[index] = '\0';

    free(result);

    return answer;
}