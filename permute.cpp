void permuteDFS(vector<int>& nums, vector<int>& cur, vector<bool>& used, vector<vector<int>>& res) {
    if (cur.size() == nums.size()) { res.push_back(cur); return; }
    for (int i = 0; i < nums.size(); ++i) {
        if (used[i]) continue;
        used[i] = true;
        cur.push_back(nums[i]);
        permuteDFS(nums, cur, used, res);
        cur.pop_back();
        used[i] = false;
    }
}
vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> res;
    vector<int> cur;
    vector<bool> used(nums.size(), false);
    permuteDFS(nums, cur, used, res);
    return res;
}
