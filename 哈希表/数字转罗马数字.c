char* intToRoman(int num) {
    char *a = malloc(sizeof(char) * 20);
    int nowp = 0;

    int values[] = {
        1000, 900, 500, 400,
        100, 90, 50, 40,
        10, 9, 5, 4,
        1
    };

    char *symbols[] = {
        "M", "CM", "D", "CD",
        "C", "XC", "L", "XL",
        "X", "IX", "V", "IV",
        "I"
    };

    for (int i = 0; i < 13; i++) {
        while (num >= values[i]) {
            char *str = symbols[i];

            for (int j = 0; str[j] != '\0'; j++) {
                a[nowp++] = str[j];
            }

            num -= values[i];
        }
    }

    a[nowp] = '\0';
    return a;
}