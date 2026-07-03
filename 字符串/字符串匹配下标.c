int strStr(char* haystack, char* needle) {
    int lengthh = strlen(haystack);
    int lengthn = strlen(needle);

    if (lengthn == 0) {
        return 0;
    }

    /*
    comes[j] 表示：
    needle[j] 失配时，
    needle 应该回退到哪个下标继续比较。

    comes[0] = -1 表示：
    needle 第 0 位就失配时，
    haystack 向后走一位。
    */
    int comes[10001];

    int i = 0;
    int j = -1;

    comes[0] = -1;

    /*
    构造 next / comes 数组
    */
    while (i < lengthn - 1) {
        if (j == -1 || needle[i] == needle[j]) {
            i++;
            j++;
            comes[i] = j;
        } else {
            j = comes[j];
        }
    }

    /*
    i：haystack 下标
    j：needle 下标
    */
    i = 0;
    j = 0;

    while (i < lengthh && j < lengthn) {
        if (j == -1 || haystack[i] == needle[j]) {
            i++;
            j++;
        } else {
            j = comes[j];
        }
    }

    if (j == lengthn) {
        return i - j;
    }

    return -1;
}