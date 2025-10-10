#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 9e18;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin>>n;
    vector<vector<ll>> w(n, vector<ll>(n));
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin>>w[i][j];
    if(n<=20){
        int N = 1<<n;
        vector<vector<ll>> dp(N, vector<ll>(n, INF));
        dp[1][0]=0;
        for(int mask=1;mask<N;mask++){
            for(int u=0;u<n;u++) if((mask>>u)&1){
                if(dp[mask][u]==INF) continue;
                for(int v=0;v<n;v++) if(!((mask>>v)&1)){
                    dp[mask|(1<<v)][v] = min(dp[mask|(1<<v)][v], dp[mask][u] + w[u][v]);
                }
            }
        }
        ll ans=INF;
        for(int u=0;u<n;u++) ans = min(ans, dp[N-1][u] + w[u][0]);
        cout<<ans<<"\n";
    } else {
        cout<<"n>20: use meet-in-the-middle (omitted due to length). Use Held-Karp for n<=20.\n";
    }
}
;
