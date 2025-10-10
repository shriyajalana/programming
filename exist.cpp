bool existDFS(vector<vector<char>>& board, string& word, int r, int c, int idx) {
    if (idx == word.size()) return true;
    if (r < 0 || c < 0 || r >= board.size() || c >= board[0].size()) return false;
    if (board[r][c] != word[idx]) return false;
    char tmp = board[r][c];
    board[r][c] = '#';
    bool found = existDFS(board, word, r+1, c, idx+1) ||
                 existDFS(board, word, r-1, c, idx+1) ||
                 existDFS(board, word, r, c+1, idx+1) ||
                 existDFS(board, word, r, c-1, idx+1);
    board[r][c] = tmp;
    return found;
}
bool exist(vector<vector<char>>& board, string word) {
    for (int i = 0; i < board.size(); ++i)
        for (int j = 0; j < board[0].size(); ++j)
            if (existDFS(board, word, i, j, 0)) return true;
    return false;
}