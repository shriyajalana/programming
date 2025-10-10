double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
    if (a.size() > b.size()) swap(a, b);
    int m = a.size(), n = b.size(), half = (m + n + 1) / 2;
    int lo = 0, hi = m;
    while (lo <= hi) {
        int i = (lo + hi) / 2;
        int j = half - i;
        int aL = (i == 0) ? INT_MIN : a[i - 1];
        int aR = (i == m) ? INT_MAX : a[i];
        int bL = (j == 0) ? INT_MIN : b[j - 1];
        int bR = (j == n) ? INT_MAX : b[j];
        if (aL <= bR && bL <= aR) {
            if ((m + n) % 2)
                return max(aL, bL);
            return (max(aL, bL) + min(aR, bR)) / 2.0;
        } else if (aL > bR)
            hi = i - 1;
        else
            lo = i + 1;
    }
    return 0.0;
}
