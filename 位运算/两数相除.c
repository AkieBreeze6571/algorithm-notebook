int divide(int dividend, int divisor) {
    int result;
    int temp;
    int multiple;
    int negative;

    if (dividend == 0) {
        return 0;
    }

    if (dividend == -2147483648 && divisor == -1) {
        return 2147483647;
    }

    if (dividend == -2147483648 && divisor == 1) {
        return -2147483648;
    }

    negative = (dividend < 0) != (divisor < 0);

    if (dividend > 0) {
        dividend = -dividend;
    }

    if (divisor > 0) {
        divisor = -divisor;
    }

    result = 0;

    while (dividend <= divisor) {
        temp = divisor;
        multiple = 1;

        while (temp >= -2147483648 - temp &&
               dividend <= temp + temp) {
            temp += temp;
            multiple += multiple;
        }

        dividend -= temp;
        result += multiple;
    }

    if (negative) {
        return -result;
    }

    return result;
}