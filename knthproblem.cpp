#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (1LL<<60);
struct Edge{int v; ll w;};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m,s,t,k;
    if(!(cin>>n>>m>>s>>t>>k)) return 0;
    vector<vector<Edge>> g(n), gr(n);
    for(int i=0;i<m;i++){
        int u,v; ll w; cin>>u>>v>>w;
        g[u].push_back({v,w});
        gr[v].push_back({u,w});
    }
    // potentials: shortest dist from node to t
    vector<ll> pot(n, INF);
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<>> pq;
    pot[t]=0; pq.push({0,t});
    while(!pq.empty()){
        auto [d,u]=pq.top(); pq.pop();
        if(d!=pot[u]) continue;
        for(auto &e: gr[u]){
            if(pot[e.v] > d + e.w){
                pot[e.v] = d + e.w;
                pq.push({pot[e.v], e.v});
            }
        }
    }
    if(pot[s]==INF){ cout<<"No path\n"; return 0; }
    // A* style for k shortest simple paths (may repeat nodes but ensure distinct paths by content)
    struct State{ ll cost; int node; vector<int> path; };
    struct Cmp{ bool operator()(State const& a, State const& b) const { return a.cost > b.cost; } };
    priority_queue<State, vector<State>, Cmp> q;
    q.push({pot[s], s, {s}});
    vector<vector<int>> answers;
    while(!q.empty() && (int)answers.size()<k){
        auto st = q.top(); q.pop();
        int u = st.node;
        ll gcost = st.cost - pot[u];
        if(u==t){
            answers.push_back(st.path);
            cout << "Path " << answers.size() << " cost " << gcost << ": ";
            for(int v: st.path) cout<<v<<(v==t?'\n':' ');
            continue;
        }
        for(auto &e: g[u]){
            if(pot[e.v]==INF) continue;
            auto np = st.path; np.push_back(e.v);
            ll newcost = gcost + e.w + pot[e.v];
            q.push({newcost, e.v, np});
        }
    }
    if(answers.empty()) cout<<"No path found\n";
    return 0;
}
