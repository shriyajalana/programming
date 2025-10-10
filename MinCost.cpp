#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (1LL<<60);
struct Edge{ int to; int rev; int cap; ll cost; };
struct MinCost {
    int N;
    vector<vector<Edge>> G; vector<ll> pot, dist; vector<int> pv_v, pv_e;
    MinCost(int n):N(n),G(n),pot(n,0),dist(n),pv_v(n),pv_e(n){}
    void addEdge(int u,int v,int cap,ll cost){
        G[u].push_back({v, (int)G[v].size(), cap, cost});
        G[v].push_back({u, (int)G[u].size()-1, 0, -cost});
    }
    pair<int,ll> minCostFlow(int s,int t,int maxf){
        int flow=0; ll cost=0;
        priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<>> pq;
        while(flow<maxf){
            fill(dist.begin(), dist.end(), INF);
            dist[s]=0; pq.push({0,s});
            while(!pq.empty()){
                auto [d,u]=pq.top(); pq.pop();
                if(d!=dist[u]) continue;
                for(int i=0;i<(int)G[u].size();++i){
                    auto &e = G[u][i];
                    if(e.cap>0 && dist[e.to] > dist[u] + e.cost + pot[u] - pot[e.to]){
                        dist[e.to] = dist[u] + e.cost + pot[u] - pot[e.to];
                        pv_v[e.to]=u; pv_e[e.to]=i;
                        pq.push({dist[e.to], e.to});
                    }
                }
            }
            if(dist[t]==INF) break;
            for(int i=0;i<N;i++) if(dist[i]<INF) pot[i]+=dist[i];
            int addf = maxf - flow;
            int v=t;
            while(v!=s){ addf = min(addf, G[pv_v[v]][pv_e[v]].cap); v=pv_v[v]; }
            flow += addf;
            cost += (ll)addf * pot[t];
            v=t;
            while(v!=s){
                auto &e = G[pv_v[v]][pv_e[v]];
                e.cap -= addf;
                G[v][e.rev].cap += addf;
                v = pv_v[v];
            }
        }
        return {flow, cost};
    }
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m; if(!(cin>>n>>m)) return 0;
    MinCost M(n);
    for(int i=0;i<m;i++){
        int u,v,c, w; cin>>u>>v>>c>>w;
        M.addEdge(u,v,c,w);
    }
    int s,t,F; cin>>s>>t>>F;
    auto res = M.minCostFlow(s,t,F);
    cout<<"Flow: "<<res.first<<" Cost: "<<res.second<<"\n";
}
