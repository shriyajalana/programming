int minDistance(string word1, string word2) {
    int n = word1.size(), m = word2.size();
    vector<int> dp(m+1);
    for (int j = 0; j <= m; ++j) dp[j] = j;
    for (int i = 1; i <= n; ++i) {
        vector<int> ndp(m+1);
        ndp[0] = i;
        for (int j = 1; j <= m; ++j) {
            if (word1[i-1] == word2[j-1]) ndp[j] = dp[j-1];
            else ndp[j] = 1 + min({dp[j], ndp[j-1], dp[j-1]}); // delete, insert, replace
        }
        dp.swap(ndp);
    }
    return dp[m];
}

// -----------------------------
// End of file: you can add test stubs or main() to run specific functions.
// -----------------------------
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // Example quick sanity check (uncomment to test small functions):
    /*
    vector<int> v = {2,7,11,15};
    auto ts = threeSum(v); // will be empty for this input
    cout << "threeSum size: " << ts.size() << "\n";
    */
    return 0;
}