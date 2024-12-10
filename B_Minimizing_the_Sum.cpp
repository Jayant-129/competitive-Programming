#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<vector<ll>> dp;
vector<ll> v;
ll dpans(ll i, ll k){
    if(i < 0){
        return 0;
    }
    if(dp[i][k] != -1){
        return dp[i][k];
    }
    ll ans = v[i] + dpans(i - 1, k);
    ll mini = v[i];
    for(int j = 1; j <= k && i >= j; j++){
        mini = min(v[i - j],mini);
        ans = min(mini * (j + 1) + dpans(i - j - 1,k - j), ans);
    }
    return dp[i][k] = ans;
}

void solve(){
    ll n, k; cin >> n >> k;
    dp.resize(n,vector<ll>(k + 1,-1));
    v.resize(n,0); for(auto& x: v) cin >> x;
    ll ans = dpans(n - 1,k);
    cout << ans << endl;
    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j <= k; j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    dp.clear();
    v.clear();
}

int main(){
  ll t; cin >> t;
  while(t--){
    solve();
  }
}