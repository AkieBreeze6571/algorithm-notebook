int uniquePaths(int m, int n) {
    int total = m + n - 2;
    int choose = m - 1;

    if (choose > n - 1) {
        choose = n - 1;
    }

    long long result = 1;

    for (int i = 1; i <= choose; i++) {
        result = result * (total - choose + i) / i;
    }

    return (int)result;
}