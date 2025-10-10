// N-Queens (backtracking)
vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> res;
    vector<int> cols(n, -1);
    function<void(int, vector<bool>&, vector<bool>&, vector<bool>&)> dfs;
    dfs = [&](int r, vector<bool>& col, vector<bool>& diag1, vector<bool>& diag2) {
        if (r == n) {
            vector<string> bd(n, string(n, '.'));
            for (int i = 0; i < n; ++i) bd[i][cols[i]] = 'Q';
            res.push_back(bd);
            return;
        }
        for (int c = 0; c < n; ++c) {
            if (col[c] || diag1[r+c] || diag2[r-c + n]) continue;
            cols[r] = c;
            col[c] = diag1[r+c] = diag2[r-c + n] = true;
            dfs(r+1, col, diag1, diag2);
            col[c] = diag1[r+c] = diag2[r-c + n] = false;
        }
    };
    vector<bool> col(n,false), d1(2*n,false), d2(2*n,false);
    dfs(0, col, d1, d2);
    return res;
}
