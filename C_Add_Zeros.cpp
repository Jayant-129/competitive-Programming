#include<bits/stdc++.h>
using namespace std;
#define ll long long
map<ll,vector<ll>> mp;
map<ll,ll> dp;
ll dfs(ll i){
    if(mp.find(i) == mp.end()){
        return i;
    }
    if(dp.find(i) != dp.end()){
        return dp[i];
    }
    ll ans = i;
    for(auto& j: mp[i]){
        if(j != 1){
            ans = max(ans,dfs(i + j - 1));
        }
    }
    return dp[i] = ans;
}
void solve(){
    ll n; cin >> n;
    for(int i = 1; i <= n; i++){
        ll x; cin >> x;
        mp[x + i].push_back(i);
    }
    cout << dfs(n + 1) - 1 << endl;
    mp.clear();
    dp.clear();
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  ll t; cin >> t;
  while(t--){
    solve();
  }
}