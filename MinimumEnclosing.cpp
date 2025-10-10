#include <bits/stdc++.h>
using namespace std;
struct P{ double x,y; };
double dist(const P&a,const P&b){ double dx=a.x-b.x, dy=a.y-b.y; return sqrt(dx*dx+dy*dy); }
struct Circle{ P c; double r; };
Circle circleFrom2(const P&a,const P&b){ P c{(a.x+b.x)/2,(a.y+b.y)/2}; return {c, dist(a,b)/2}; }
Circle circleFrom3(const P &A,const P &B,const P &C){
    double a = B.x - A.x, b = B.y - A.y;
    double c = C.x - A.x, d = C.y - A.y;
    double e = a*(A.x+B.x) + b*(A.y+B.y);
    double f = c*(A.x+C.x) + d*(A.y+C.y);
    double g = 2*(a*(C.y-B.y)-b*(C.x-B.x));
    if(fabs(g)<1e-12) return {{0,0}, -1};
    P o{ (d*e - b*f)/g, (a*f - c*e)/g };
    return {o, dist(o,A)};
}
bool contains(const Circle &c, const P &p){ return dist(c.c,p) <= c.r + 1e-9; }
Circle welzl(vector<P>& pts, vector<P>& R, int n){
    if(n==0 || R.size()==3){
        if(R.empty()) return {{0,0},0};
        if(R.size()==1) return {R[0],0};
        if(R.size()==2) return circleFrom2(R[0],R[1]);
        return circleFrom3(R[0],R[1],R[2]);
    }
    P p = pts[n-1];
    Circle D = welzl(pts, R, n-1);
    if(D.r>=0 && contains(D,p)) return D;
    R.push_back(p);
    Circle D2 = welzl(pts, R, n-1);
    R.pop_back();
    return D2;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; if(!(cin>>n)) return 0;
    vector<P> pts(n);
    for(int i=0;i<n;i++) cin>>pts[i].x>>pts[i].y;
    random_shuffle(pts.begin(), pts.end());
    vector<P> R;
    Circle ans = welzl(pts, R, n);
    cout<<fixed<<setprecision(10)<<ans.c.x<<" "<<ans.c.y<<" "<<ans.r<<"\n";
}
