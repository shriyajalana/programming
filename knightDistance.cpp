#include <bits/stdc++.h>
using namespace std;

int knightDistance(int x, int y) {
    x = abs(x), y = abs(y);
    vector<vector<int>> moves = {{1,2},{2,1},{-1,2},{2,-1},{-2,1},{1,-2},{-1,-2},{-2,-1}};
    queue<pair<int,int>> q;
    set<pair<int,int>> vis;
    q.push({0,0});
    vis.insert({0,0});
    int steps=0;

    while(!q.empty()){
        int sz=q.size();
        while(sz--){
            auto [cx,cy]=q.front(); q.pop();
            if(cx==x && cy==y) return steps;
            for(auto &m:moves){
                int nx=cx+m[0], ny=cy+m[1];
                if(!vis.count({nx,ny})){
                    vis.insert({nx,ny});
                    q.push({nx,ny});
                }
            }
        }
        steps++;
    }
    return -1;
}

int main(){
    cout << knightDistance(5,5) << endl;
}
