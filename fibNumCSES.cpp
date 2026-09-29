#include <bits/stdc++.h>
typedef long long ll;
using namespace std;


ll mod = 1e9+7;

ll binPow(ll base, ll pw){
    ll ans = 1;
    while (pw > 0){
        if (pw%2) ans = (ans+base)%mod;
        base = (base*base)%mod;
        pw /= 2;
    }
    return ans;
}

vector<vector<ll>> mul(vector<vector<ll>> A, vector<vector<ll>> B){
    int n = A.size();
    int m = B[0].size();
    vector<vector<ll>> ans(n, vector<ll>(m));

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            for (int k = 0; k < B.size(); k++){
                ans[i][j] = (ans[i][j] + (A[i][k] * B[k][j]))%mod;
                
            }
        }
    }

    return ans;
}

vector<vector<ll>> matpow(vector<vector<ll>>& A, ll pow){
    vector<vector<ll>> ans = {{1, 0}, {0, 1}};
    while (pow>0){
        if(pow%2) ans = mul(ans, A);
        A = mul(A, A);
        pow /= 2;
    }
    return ans;
}

int main(){
    ll n;
    cin >> n;
    
    
    vector<vector<ll>> A = {{1, 1}, {1, 0}};
    A = matpow(A, n-1);
    vector<vector<ll>> B = {{1, 0}};
    vector<vector<ll>> ans;
    ans = mul(A, B);
    if (n <= 1) cout << n;
    else cout << ans[0][0];
}