bool isValidSudoku(char** board, int boardSize, int* boardColSize) {
    int row[9][9] = {0};
    int col[9][9] = {0};
    int box[9][9] = {0};

    int i;
    int j;
    int num;
    int boxIndex;

    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {

            if (board[i][j] == '.') {
                continue;
            }

            num = board[i][j] - '1';

            boxIndex = (i / 3) * 3 + j / 3;

            row[i][num]++;
            col[j][num]++;
            box[boxIndex][num]++;

            if (row[i][num] > 1 ||
                col[j][num] > 1 ||
                box[boxIndex][num] > 1) {
                return false;
            }
        }
    }

    return true;
}