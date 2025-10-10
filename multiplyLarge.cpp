#include <bits/stdc++.h>
using namespace std;

string multiplyLarge(string a, string b) {
    int n = a.size(), m = b.size();
    vector<int> res(n + m, 0);

    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            int mul = (a[i] - '0') * (b[j] - '0');
            int sum = mul + res[i + j + 1];
            res[i + j + 1] = sum % 10;
            res[i + j] += sum / 10;
        }
    }

    string ans = "";
    for (int num : res)
        if (!(ans.empty() && num == 0)) ans.push_back(num + '0');
    return ans.empty() ? "0" : ans;
}

int main() {
    string a = "123456789123456789";
    string b = "987654321987654321";
    cout << multiplyLarge(a, b) << endl;
}
