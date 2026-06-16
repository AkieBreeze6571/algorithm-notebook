bool isMatch(char* s, char* p) {
    if (p[0] == '\0') {
        return s[0] == '\0';
    }

    bool firstMatch = false;

    if (s[0] != '\0' && (p[0] == s[0] || p[0] == '.')) {
        firstMatch = true;
    }

    if (p[1] == '*') {
        return isMatch(s, p + 2) ||
               (firstMatch && isMatch(s + 1, p));
    }

    return firstMatch && isMatch(s + 1, p + 1);
}