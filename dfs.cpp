#include <bits/stdc++.h>
using namespace std;

bool dfs(int u, vector<vector<int>>& g, vector<int>& vis, vector<int>& order) {
    vis[u] = 1;
    for (int v : g[u]) {
        if (vis[v] == 1) return false; // cycle
        if (vis[v] == 0 && !dfs(v, g, vis, order)) return false;
    }
    vis[u] = 2;
    order.push_back(u);
    return true;
}

int main() {
    int n = 6;
    vector<vector<int>> g = {
        {1, 2}, {3}, {3}, {4}, {5}, {}
    };
    vector<int> vis(n, 0), order;

    for (int i = 0; i < n; i++)
        if (vis[i] == 0 && !dfs(i, g, vis, order)) {
            cout << "Cycle detected\n";
            return 0;
        }

    reverse(order.begin(), order.end());
    for (int x : order) cout << x << " ";
    cout << endl;
}
