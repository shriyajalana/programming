#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int H,W; cin>>H>>W;
    vector<string> grid(H);
    for(int i=0;i<H;i++) cin>>grid[i];
    vector<vector<int>> dist(H, vector<int>(W, INT_MAX));
    map<char, vector<pii>> tele;
    pii S,T;
    for(int i=0;i<H;i++) for(int j=0;j<W;j++){
        char c=grid[i][j];
        if(c=='S') S={i,j};
        if(c=='T') T={i,j};
        if(isalpha(c)) tele[c].push_back({i,j});
    }
    deque<pii> dq;
    dist[S.first][S.second]=0; dq.push_back(S);
    vector<int> dr={-1,1,0,0}, dc={0,0,-1,1};
    vector<bool> used('z'+1,false);
    while(!dq.empty()){
        auto [r,c] = dq.front(); dq.pop_front();
        int d = dist[r][c];
        if(make_pair(r,c)==T) break;
        for(int k=0;k<4;k++){
            int nr=r+dr[k], nc=c+dc[k];
            if(nr<0||nr>=H||nc<0||nc>=W) continue;
            if(grid[nr][nc]=='#') continue;
            if(dist[nr][nc] > d+1){ dist[nr][nc]=d+1; dq.push_back({nr,nc}); }
        }
        char ch = grid[r][c];
        if(isalpha(ch) && !used[ch]){
            for(auto &p: tele[ch]){
                if(dist[p.first][p.second] > d){
                    dist[p.first][p.second] = d;
                    dq.push_front(p);
                }
            }
            used[ch]=true;
        }
    }
    int ans = dist[T.first][T.second];
    if(ans==INT_MAX) cout<<"-1\n"; else cout<<ans<<"\n";
    return 0;
}
