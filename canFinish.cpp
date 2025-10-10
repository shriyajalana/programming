// Course Schedule (can finish all courses?) - topological sort (Kahn)
bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> g(numCourses);
    vector<int> indeg(numCourses, 0);
    for (auto &pr : prerequisites) {
        g[pr[1]].push_back(pr[0]);
        indeg[pr[0]]++;
    }
    queue<int> q;
    for (int i = 0; i < numCourses; ++i) if (indeg[i] == 0) q.push(i);
    int cnt = 0;
    while (!q.empty()) {
        int u = q.front(); q.pop(); cnt++;
        for (int v : g[u]) {
            if (--indeg[v] == 0) q.push(v);
        }
    }
    return cnt == numCourses;
}
