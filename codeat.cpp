#include<bits/stdc++.h>
using namespace std;
#define ld long double
#define ll long long
vector<vector<ld>> dp;
void solve(){
    ll n;cin >> n; vector<ld> v(n, 0);for(int i = 0; i < n; i++) cin >> v[i];
    dp.resize(n,vector<ld>(n + 1,0));
    dp[0][0] = 1.0-v[0], dp[0][1] = v[0];
    for(ll i = 1; i < n; i++){
        dp[i][0] = dp[i-1][0] * (1.0 - v[i]);
        for(ll j = 1; j <= (i + 1); j++){
            dp[i][j] = dp[i-1][j] * (1.0 - v[i]) + dp[i - 1][j-1] * v[i];
        }
    }
    ld ans = 0;
    for(ll i = (n/2 + 1); i <= n; i++){
        ans += dp[n-1][i];
    }
    cout << setprecision(10) << ans << endl;
}

int main(){
  ll t =1;
 while(t-- > 0){
    solve();
  }
}