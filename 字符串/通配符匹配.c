#include <stdbool.h>

bool isMatch(char* s, char* p) {
    int i;
    int j;
    int star;
    int match;

    i = 0;
    j = 0;

    star = -1;
    match = 0;

    while (s[i] != '\0') {

        /* 普通字符相等，或者? */
        if (p[j] == s[i] || p[j] == '?') {
            i++;
            j++;
        }

        /* 遇到* */
        else if (p[j] == '*') {
            star = j;
            match = i;

            j++;
        }

        /* 当前匹配失败，但之前存在* */
        else if (star != -1) {

            /* 回到最近的*后面 */
            j = star + 1;

            /* 让*多匹配一个字符 */
            match++;
            i = match;
        }

        /* 没有*可以救场 */
        else {
            return false;
        }
    }

    /*
     * s已经全部匹配完。
     * p剩下的只能全部是*
     */
    while (p[j] == '*') {
        j++;
    }

    return p[j] == '\0';
}