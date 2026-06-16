int expand(char *s, int left, int right, int n) {
    while (left >= 0 && right < n && s[left] == s[right]) {
        left--;
        right++;
    }

    return right - left - 1;
}

char* longestPalindrome(char* s) {
    int n = strlen(s);

    char *ans = malloc(sizeof(char) * (n + 1));
    if (ans == NULL) {
        return NULL;
    }

    if (n == 0) {
        ans[0] = '\0';
        return ans;
    }

    int start = 0;
    int maxLen = 1;

    for (int i = 0; i < n; i++) {
        int len1 = expand(s, i, i, n);
        int len2 = expand(s, i, i + 1, n);

        int len = len1 > len2 ? len1 : len2;

        if (len > maxLen) {
            maxLen = len;
            start = i - (len - 1) / 2;
        }
    }

    for (int i = 0; i < maxLen; i++) {
        ans[i] = s[start + i];
    }

    ans[maxLen] = '\0';

    return ans;
}