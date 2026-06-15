int lengthOfLongestSubstring(char* s) {
    int last[128];
    int i;
    int left = 0;
    int right;
    int maxLen = 0;

    for (i = 0; i < 128; i++) {
        last[i] = -1;
    }

    for (right = 0; s[right] != '\0'; right++) {
        char c = s[right];

        if (last[c] >= left) {
            left = last[c] + 1;
        }

        last[c] = right;

        if (right - left + 1 > maxLen) {
            maxLen = right - left + 1;
        }
    }

    return maxLen;
}