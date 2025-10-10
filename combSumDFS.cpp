void combSumDFS(vector<int>& candidates, int start, int target, vector<int>& cur, vector<vector<int>>& res) {
    if (target == 0) { res.push_back(cur); return; }
    if (target < 0) return;
    for (int i = start; i < candidates.size(); ++i) {
        cur.push_back(candidates[i]);
        combSumDFS(candidates, i, target - candidates[i], cur, res);
        cur.pop_back();
    }
}
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> res;
    vector<int> cur;
    combSumDFS(candidates, 0, target, cur, res);
    return res;
}
