#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 998244353, G = 3;
ll modpow(ll a,ll e){ ll r=1; while(e){ if(e&1) r=r*a%MOD; a=a*a%MOD; e>>=1;} return r;}
void ntt(vector<ll>& a, bool invert){
    int n=a.size();
    for(int i=1,j=0;i<n;i++){
        int bit = n>>1;
        for(; j&bit; bit>>=1) j^=bit;
        j ^= bit;
        if(i<j) swap(a[i],a[j]);
    }
    for(int len=2; len<=n; len<<=1){
        ll wlen = modpow(G, (MOD-1)/len);
        if(invert) wlen = modpow(wlen, MOD-2);
        for(int i=0;i<n;i+=len){
            ll w=1;
            for(int j=0;j<len/2;j++){
                ll u=a[i+j], v=a[i+j+len/2]*w%MOD;
                a[i+j] = (u+v)%MOD;
                a[i+j+len/2] = (u-v+MOD)%MOD;
                w = w * wlen % MOD;
            }
        }
    }
    if(invert){
        ll invn = modpow(n, MOD-2);
        for(ll &x: a) x = x * invn % MOD;
    }
}
vector<ll> multiply(vector<ll> a, vector<ll> b){
    int n=1; while(n < (int)(a.size()+b.size())) n<<=1;
    a.resize(n); b.resize(n);
    ntt(a,false); ntt(b,false);
    for(int i=0;i<n;i++) a[i] = a[i]*b[i]%MOD;
    ntt(a,true);
    return a;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m; cin>>n>>m;
    vector<ll> A(n), B(m);
    for(int i=0;i<n;i++) cin>>A[i];
    for(int i=0;i<m;i++) cin>>B[i];
    auto C = multiply(A,B);
    for(size_t i=0;i<n+m-1;i++) cout<<C[i]<<(i+1==n+m-1?'\n':' ');
}
  
