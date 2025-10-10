#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1e9+7;

vector<vector<ll>> multiply(vector<vector<ll>>& A, vector<vector<ll>>& B) {
    vector<vector<ll>> C(2, vector<ll>(2, 0));
    for (int i=0;i<2;i++)
        for (int j=0;j<2;j++)
            for (int k=0;k<2;k++)
                C[i][j] = (C[i][j] + A[i][k]*B[k][j]) % MOD;
    return C;
}

vector<vector<ll>> power(vector<vector<ll>> A, ll n) {
    vector<vector<ll>> res = {{1,0},{0,1}};
    while(n>0){
        if(n&1) res = multiply(res,A);
        A = multiply(A,A);
        n >>= 1;
    }
    return res;
}

ll fibonacci(ll n){
    if(n==0) return 0;
    vector<vector<ll>> F = {{1,1},{1,0}};
    return power(F,n-1)[0][0];
}

int main(){
    cout << fibonacci(50) << endl; // 12586269025 % MOD
}
