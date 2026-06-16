void my_strcpy(char *src, char *dest, int size) {
    int i = 0;

    while (src[i] != '\0' && i < size - 1) {
        dest[i] = src[i];
        i++;
    }

    dest[i] = '\0';
}

char* longestPalindrome(char* s) {
    int l, r;
    int findl = 0;
    int findr = 0;
    int length = 1;

    int n = strlen(s);

    char *a = malloc(sizeof(char) * (n + 1));
    if (a == NULL) {
        return NULL;
    }

    if (n == 0) {
        a[0] = '\0';
        return a;
    }

    int right = n - 1;

    for (int i = 0; i < right; i++) {
        for (int j = right; j > i; j--) {
            l = i;
            r = j;

            while (l < r && s[l] == s[r]) {
                l++;
                r--;
            }

            if (l >= r && j - i + 1 > length) {
                findl = i;
                findr = j;
                length = j - i + 1;
            }
        }
    }

    my_strcpy(&s[findl], a, length + 1);

    return a;
}