#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n;
vector<vector<int>> g;
vector<int> sz, parent, depth, heavy, head, pos;
int curPos=0;
vector<ll> seg;
vector<ll> base;
int dfs(int v,int p){
    sz[v]=1; parent[v]=p; depth[v]= (p==-1?0:depth[p]+1);
    int maxsz=0;
    for(int c:g[v]) if(c!=p){
        int s = dfs(c,v);
        if(s>maxsz){ maxsz=s; heavy[v]=c; }
        sz[v]+=s;
    }
    return sz[v];
}
void decompose(int v,int h){
    head[v]=h; pos[v]=curPos++; base[pos[v]] = 0; // assign initial as needed
    if(heavy[v]!=-1) decompose(heavy[v], h);
    for(int c:g[v]) if(c!=parent[v] && c!=heavy[v]) decompose(c,c);
}
// segment tree (sum)
void segBuild(int idx,int l,int r){ if(l==r){ seg[idx]=base[l]; return; } int m=(l+r)/2; segBuild(idx*2,l,m); segBuild(idx*2+1,m+1,r); seg[idx]=seg[idx*2]+seg[idx*2+1]; }
void segUpd(int idx,int l,int r,int p,ll val){ if(l==r){ seg[idx]=val; return; } int m=(l+r)/2; if(p<=m) segUpd(idx*2,l,m,p,val); else segUpd(idx*2+1,m+1,r,p,val); seg[idx]=seg[idx*2]+seg[idx*2+1]; }
ll segQuery(int idx,int l,int r,int ql,int qr){ if(ql>r||qr<l) return 0; if(ql<=l&&r<=qr) return seg[idx]; int m=(l+r)/2; return segQuery(idx*2,l,m,ql,qr)+segQuery(idx*2+1,m+1,r,ql,qr); }
ll queryPath(int a,int b){
    ll res=0;
    while(head[a]!=head[b]){
        if(depth[head[a]] < depth[head[b]]) swap(a,b);
        res += segQuery(1,0,n-1,pos[head[a]], pos[a]);
        a = parent[head[a]];
    }
    if(depth[a] > depth[b]) swap(a,b);
    res += segQuery(1,0,n-1,pos[a], pos[b]);
    return res;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    g.assign(n,{}); sz.assign(n,0); parent.assign(n,-1); depth.assign(n,0); heavy.assign(n,-1); head.assign(n,0); pos.assign(n,0);
    base.assign(n,0);
    for(int i=0;i<n-1;i++){ int u,v; cin>>u>>v; g[u].push_back(v); g[v].push_back(u); }
    dfs(0,-1); decompose(0,0);
    seg.assign(4*n,0);
    segBuild(1,0,n-1);
    // example queries
    cout<<"HLD built. Use segUpd and queryPath for updates and queries.\n";
}
