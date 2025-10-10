string longestPalindrome(string s) {
    int start = 0, len = 0;
    auto expand = [&](int l, int r) {
        while (l >= 0 && r < s.size() && s[l] == s[r]) l--, r++;
        return pair<int, int>{l + 1, r - l - 1};
    };
    for (int i = 0; i < s.size(); i++) {
        auto [l1, len1] = expand(i, i);
        auto [l2, len2] = expand(i, i + 1);
        if (len1 > len) start = l1, len = len1;
        if (len2 > len) start = l2, len = len2;
    }
    return s.substr(start, len);
}
