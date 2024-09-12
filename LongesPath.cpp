#include<bits/stdc++.h>
using namespace std;
#define ll long long

map<ll,ll> mp;
ll dp(vector<vector<ll>>& adj,ll i){
    if(mp.find(i) != mp.end()){
        return mp[i];
    }
    mp[i] = 0;
    for(auto& j: adj[i]){
        mp[i] = max(mp[i],dp(adj,j) + 1);
    }
    return mp[i];
}

int main(){
  ll n , m;
  cin >> n >> m;
  vector<vector<ll>> adj(n + 1);
  for(ll i = 0; i < m; i++){
    ll x , y;cin >> x >> y;
    adj[x].push_back(y);
  }
  for(ll i = 1; i <= n; i++){
    if(mp.find(i) == mp.end()){
        dp(adj,i);
    }
  }
  ll ans = 0;
  for(auto& [i,j]: mp){
    ans = max(ans,j);
    //cout << i << " " << j << endl;
  }
  cout << ans << endl;
}