#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<vector<ll>> adj;
vector<ll> dep;
vector<ll> v;
ll dfs(ll i, ll par){
    dep[i] = dep[par] + 1;
    ll maxi = dep[i];
    for(auto& j: adj[i]){
        if(j != par){
            maxi = max(maxi,dfs(j,i));
        }
    }
    v[dep[i]]++;
    v[maxi + 1]--;
    return maxi;
}
void solve(){
    ll n; cin >> n;
    adj.clear(); v.clear(); dep.clear();
    adj.resize(n + 5); dep.resize(n + 5,0);
    v.resize(n + 5, 0);
    for(int i = 1; i < n; i++){
        ll u , v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,0);
    ll ans = n;
    for(int i = 1; i <= n; i++){
        if(i) v[i] += v[i - 1];
        ans = min(ans,n - v[i]);
    }
    cout << ans << endl;
}
int main(){
  ll t; cin >> t;
  while(t--){
    solve();
  }
}