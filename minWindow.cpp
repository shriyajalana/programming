// Return minimum substring in s containing all chars of t.
// Sliding window with counts.
string minWindow(string s, string t) {
    if (s.empty() || t.empty()) return "";
    vector<int> need(128,0);
    for (char c : t) need[c]++;
    int required = 0;
    for (int c = 0; c < 128; ++c) if (need[c] > 0) ++required;
    int l = 0, formed = 0;
    vector<int> window(128,0);
    int minLen = INT_MAX, minL = 0;
    for (int r = 0; r < s.size(); ++r) {
        char c = s[r];
        window[c]++;
        if (need[c] > 0 && window[c] == need[c]) ++formed;
        while (l <= r && formed == required) {
            if (r - l + 1 < minLen) { minLen = r - l + 1; minL = l; }
            char lc = s[l++];
            window[lc]--;
            if (need[lc] > 0 && window[lc] < need[lc]) --formed;
        }
    }
    return minLen == INT_MAX ? "" : s.substr(minL, minLen);
}
