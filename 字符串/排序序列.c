char* getPermutation(int n, int k) {
    char* result = (char*)malloc(sizeof(char) * (n + 1));

    int used[n];
    for (int i = 0; i < n; i++) {
        used[i] = 0;
    }

    int sum = 1;
    int usen = n;
    int temp;
    int weiyi;

    while (usen != 1) {
        sum *= usen;
        usen--;
    }

    temp = sum;

    /* k从1开始，转换成从0开始 */
    k--;

    for (int i = 0; i < n; i++) {

        /* 当前每一个数字开头占多少种排列 */
        temp = temp / (n - i);

        /* 应该选择第几个“还没有使用”的数字 */
        weiyi = k / temp;

        int count = 0;

        for (int j = 0; j < n; j++) {
            if (used[j] == 0) {

                if (count == weiyi) {
                    result[i] = '1' + j;
                    used[j] = 1;
                    break;
                }

                count++;
            }
        }

        /* 进入这一组以后，在组内的位置 */
        k = k % temp;
    }

    result[n] = '\0';

    return result;
}