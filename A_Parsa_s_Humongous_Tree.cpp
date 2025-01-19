#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<vector<ll>> adj;
vector<vector<ll>> dp;
vector<pair<ll,ll>> v;
ll dfs(ll i,ll par, bool flag){
    if(dp[i][flag] != -1){
        return dp[i][flag];
    }
    ll prev;
    if(flag){
        prev = v[par].first;
    }
    else{
        prev = v[par].second;
    }
    ll sum = abs(prev - v[i].second);
    ll sum2 = abs(prev - v[i].first);
    for(auto& j: adj[i]){
        if(j == par){
            continue;
        }
        sum += dfs(j, i, false);
        sum2 += dfs(j,i,true);
    }
    return dp[i][flag] = max(sum,sum2);
}

void solve(){
    ll n; cin >> n;
    v.clear(); adj.clear(); dp.clear();
    dp.resize(n,vector<ll>(2,-1));
    for(int i = 0; i < n; i++){
        ll l, r; cin >> l >> r;
        v.push_back({l,r});
    }
    adj.resize(n);
    for(int i = 1; i < n; i++){
        ll x , y; cin >> x >> y;
        x--; y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    ll ans1 = 0 , ans = 0;
    for(auto& i: adj[0]){
        ans1 += dfs(i,0,false);
        ans += dfs(i,0,true);
    }
    cout << max(ans,ans1) << endl;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  ll t; cin >> t;
  while(t--){
    solve();
  }
}