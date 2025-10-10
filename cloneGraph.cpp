// Node struct defined above.
Node* cloneGraph(Node* node) {
    if (!node) return nullptr;
    unordered_map<Node*, Node*> mp;
    queue<Node*> q;
    q.push(node);
    mp[node] = new Node(node->val);
    while (!q.empty()) {
        Node* cur = q.front(); q.pop();
        for (Node* nb : cur->neighbors) {
            if (!mp.count(nb)) {
                mp[nb] = new Node(nb->val);
                q.push(nb);
            }
            mp[cur]->neighbors.push_back(mp[nb]);
        }
    }
    return mp[node];
}
