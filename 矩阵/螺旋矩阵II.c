int** generateMatrix(int n, int* returnSize, int** returnColumnSizes) {
    int** matrix = (int**)malloc(n * sizeof(int*));

    for (int i = 0; i < n; i++) {
        matrix[i] = (int*)malloc(n * sizeof(int));
    }

    int rounds = (n + 1) / 2;
    int num = 1;

    for (int i = 0; i < rounds; i++) {
        int j = i, k = i;

        /* 上边：向右 */
        for (; j < n - i; j++) {
            matrix[k][j] = num;
            num++;
        }

        j--;    // 回到右上角
        k++;    // 右上角已经填过，所以向下一格

        /* 右边：向下 */
        for (; k < n - i; k++) {
            matrix[k][j] = num;
            num++;
        }

        k--;    // 回到右下角
        j--;    // 右下角已经填过，所以向左一格

        /* 下边：向左 */
        for (; j >= i; j--) {
            matrix[k][j] = num;
            num++;
        }

        j++;    // 回到左下角
        k--;    // 左下角已经填过，所以向上一格

        /* 左边：向上 */
        for (; k > i; k--) {
            matrix[k][j] = num;
            num++;
        }
    }

    *returnSize = n;

    *returnColumnSizes = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        (*returnColumnSizes)[i] = n;
    }

    return matrix;
}