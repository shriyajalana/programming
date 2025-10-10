#include <bits/stdc++.h>
using namespace std;
struct Aho {
    struct Node{ array<int,26> nx; int link=-1; vector<int> out; Node(){ nx.fill(-1); link=-1; } };
    vector<Node> t; Aho(){ t.push_back(Node()); }
    int add(const string &s, int id){
        int v=0;
        for(char ch: s){
            int c=ch-'a';
            if(t[v].nx[c]==-1){ t[v].nx[c]=t.size(); t.push_back(Node()); }
            v=t[v].nx[c];
        }
        t[v].out.push_back(id);
        return v;
    }
    void build(){
        queue<int> q; t[0].link=0;
        for(int c=0;c<26;c++){
            if(t[0].nx[c]!=-1){ t[t[0].nx[c]].link=0; q.push(t[0].nx[c]); }
            else t[0].nx[c]=0;
        }
        while(!q.empty()){
            int v=q.front(); q.pop();
            for(int c=0;c<26;c++){
                int u=t[v].nx[c];
                if(u!=-1){ t[u].link = t[t[v].link].nx[c]; 
                    for(int id: t[t[u].link].out) t[u].out.push_back(id);
                    q.push(u);
                } else t[v].nx[c] = t[t[v].link].nx[c];
            }
        }
    }
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int p; cin>>p;
    vector<string> patterns(p);
    for(int i=0;i<p;i++) cin>>patterns[i];
    string text; cin>>text;
    Aho aho;
    for(int i=0;i<p;i++) aho.add(patterns[i], i);
    aho.build();
    vector<vector<int>> occ(p);
    int v=0;
    for(int i=0;i<(int)text.size();i++){
        int c=text[i]-'a';
        v = aho.t[v].nx[c];
        for(int id: aho.t[v].out) occ[id].push_back(i - patterns[id].size() + 1);
    }
    for(int i=0;i<p;i++){
        cout<<"Pattern "<<i<<": ";
        for(int pos: occ[i]) cout<<pos<<' ';
        cout<<"\n";
    }
}
