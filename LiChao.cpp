#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INFLL = (1LL<<62);

struct Line {
    ll m, b;
    Line(ll _m=0, ll _b=INFLL):m(_m),b(_b){}
    ll eval(ll x) const { return m*x + b; }
};

struct LiChao {
    struct Node {
        Line line;
        Node *l=0,*r=0;
        Node(Line ln=Line()):line(ln){}
    };
    Node* root;
    ll L, R;
    LiChao(ll l, ll r):root(nullptr),L(l),R(r){}
    void add_line(Line nw){ insert(root, L, R, nw); }
    void insert(Node*& node, ll l, ll r, Line nw){
        if(!node){ node = new Node(nw); return; }
        ll mid = (l + r) >> 1;
        bool left = nw.eval(l) < node->line.eval(l);
        bool m = nw.eval(mid) < node->line.eval(mid);
        if(m){
            swap(nw, node->line);
        }
        if(r==l) return;
        if(left != m) insert(node->l, l, mid, nw);
        else insert(node->r, mid+1, r, nw);
    }
    ll query(ll x){ return query(root, L, R, x); }
    ll query(Node* node, ll l, ll r, ll x){
        if(!node) return INFLL;
        ll res = node->line.eval(x);
        if(l==r) return res;
        ll mid = (l+r)>>1;
        if(x<=mid) return min(res, query(node->l, l, mid, x));
        else return min(res, query(node->r, mid+1, r, x));
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // Example usage:
    LiChao lc(-1000000000LL, 1000000000LL);
    lc.add_line(Line(2,3)); // y = 2x+3
    lc.add_line(Line(-1,10));
    cout << lc.query(5) << "\n"; // minimal y at x=5
}
