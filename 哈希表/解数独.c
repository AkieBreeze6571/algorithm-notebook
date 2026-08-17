#include <stdbool.h>

bool startask(
    int row[][9],
    int col[][9],
    int box[][9],
    char **board,
    int i,
    int j
) {
    int num;
    int boxIndex;
    int nextI;
    int nextJ;

    /* 整个棋盘已经遍历完成 */
    if (i == 9) {
        return true;
    }

    /* 计算下一个位置 */
    if (j == 8) {
        nextI = i + 1;
        nextJ = 0;
    } else {
        nextI = i;
        nextJ = j + 1;
    }

    /* 当前本来就有数字，直接去下一个位置 */
    if (board[i][j] != '.') {
        return startask(
            row,
            col,
            box,
            board,
            nextI,
            nextJ
        );
    }

    /* 当前是空格，尝试填1~9 */
    boxIndex = (i / 3) * 3 + j / 3;

    for (num = 0; num < 9; num++) {

        /* 当前数字在行、列、宫里都没有出现 */
        if (row[i][num] == 0 &&
            col[j][num] == 0 &&
            box[boxIndex][num] == 0) {

            /* 先尝试填入 */
            board[i][j] = num + '1';

            row[i][num] = 1;
            col[j][num] = 1;
            box[boxIndex][num] = 1;

            /* 继续解决下一个位置 */
            if (startask(
                    row,
                    col,
                    box,
                    board,
                    nextI,
                    nextJ
                )) {
                return true;
            }

            /* 后面走不通，撤销 */
            board[i][j] = '.';

            row[i][num] = 0;
            col[j][num] = 0;
            box[boxIndex][num] = 0;
        }
    }

    /* 1~9全部尝试过都不行 */
    return false;
}


void solveSudoku(
    char **board,
    int boardSize,
    int *boardColSize
) {
    int row[9][9] = {0};
    int col[9][9] = {0};
    int box[9][9] = {0};

    int i;
    int j;
    int num;
    int boxIndex;

    /*
     * 先把题目原本已经存在的数字
     * 记录到三个哈希表中
     */
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {

            if (board[i][j] >= '1' &&
                board[i][j] <= '9') {

                num = board[i][j] - '1';

                boxIndex =
                    (i / 3) * 3 + j / 3;

                row[i][num] = 1;
                col[j][num] = 1;
                box[boxIndex][num] = 1;
            }
        }
    }

    /* 从左上角开始回溯 */
    startask(
        row,
        col,
        box,
        board,
        0,
        0
    );
}