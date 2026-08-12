char* addBinary(char* a, char* b) {
    int posa = 0, posb = 0;
    int up = 0, res = 0;
    int length = 0;
    int i;
    char temp;

    char* result = (char*)malloc(sizeof(char) * 10002);

    while (a[posa] != '\0') {
        posa++;
    }

    while (b[posb] != '\0') {
        posb++;
    }

    posa--;
    posb--;

    while (posa >= 0 && posb >= 0) {
        res = a[posa] + b[posb] - '0' - '0' + up;
        up = 0;

        if (res >= 2) {
            res = res - 2;
            up = 1;
        }

        result[length] = res + '0';

        posa--;
        posb--;
        length++;
    }

    while (posa >= 0 || posb >= 0) {

        if (posa >= 0) {
            res = a[posa] - '0' + up;
            posa--;
        } else {
            res = b[posb] - '0' + up;
            posb--;
        }

        up = 0;

        if (res >= 2) {
            res = res - 2;
            up = 1;
        }

        result[length] = res + '0';
        length++;
    }

    /* 最后还有进位 */
    if (up == 1) {
        result[length] = '1';
        length++;
    }

    /* 字符串反转 */
    for (i = 0; i < length / 2; i++) {
        temp = result[i];
        result[i] = result[length - 1 - i];
        result[length - 1 - i] = temp;
    }

    /* 字符串结束符 */
    result[length] = '\0';

    return result;
}