bool isPalindrome(int x) {
    long long result = 0;
    int temp = x;

    if (x < 0) {
        return false;
    }

    while (temp != 0) {
        result = result * 10 + temp % 10;
        temp = temp / 10;
    }

    return result == x;
}