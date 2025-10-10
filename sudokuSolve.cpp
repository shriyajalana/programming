bool isValidSudokuPlace(vector<vector<char>>& board, int r, int c, char ch) {
    for (int i = 0; i < 9; ++i) {
        if (board[r][i] == ch) return false;
        if (board[i][c] == ch) return false;
        int br = 3*(r/3) + i/3;
        int bc = 3*(c/3) + i%3;
        if (board[br][bc] == ch) return false;
    }
    return true;
}
bool sudokuSolve(vector<vector<char>>& board) {
    for (int r = 0; r < 9; ++r) {
        for (int c = 0; c < 9; ++c) {
            if (board[r][c] == '.') {
                for (char ch = '1'; ch <= '9'; ++ch) {
                    if (isValidSudokuPlace(board, r, c, ch)) {
                        board[r][c] = ch;
                        if (sudokuSolve(board)) return true;
                        board[r][c] = '.';
                    }
                }
                return false;
            }
        }
    }
    return true;
}
void solveSudoku(vector<vector<char>>& board) {
    sudokuSolve(board);
}
