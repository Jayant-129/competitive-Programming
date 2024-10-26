#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll> v;
vector<ll> dp;
ll dpsolve(ll i){
    if(i == v.size()){
        return 0;
    }
    if(dp[i] != -1){
        return dp[i];
    }
    ll ans = INT_MAX;
    if((i + v[i] + 1) <= v.size()){
        ans = min(ans,dpsolve(i + v[i] + 1));
    }
    ans = min(ans, 1 + dpsolve(i + 1));
    dp[i] = ans;
    return dp[i];
}
void solve(){
    ll n; cin >> n;
    v.resize(n); dp.resize(n, -1);
    for(auto& x: v) cin >> x;
    cout << dpsolve(0) << endl;
    dp.clear();
    v.clear();
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  ll t; cin >> t;
  while(t--){
    solve();
  }
}