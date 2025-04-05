#include<bits/stdc++.h>
using namespace std;
#define ll long long

vector<ll> v, dp;
vector<bool> vis;

void dfs(ll& val, ll idx){
    vis[idx] = true;
    ll next = v[idx];

    if(!vis[next]){
        val++;
        dfs(val, next);
    }
    dp[idx] = val;
}

void solve(){
    ll n; cin >> n;

    v.resize(n + 1,0), dp.resize(n + 1,0), vis.resize(n + 1,false);
    for(int i = 1; i <= n; i++){
        cin >> v[i];
    }

    ll ans = 0;

    for(int i = 1; i <= n; i++){
        ll x; cin >> x;
        if(!vis[x]){
            ll val = 1;
            dfs(val,x);
            ans += dp[x];
        }
        cout << ans << " ";
    }
    cout << endl;
    v.clear(), dp.clear(), vis.clear();
}

int main(){
  ll t; cin >> t;
  while(t--){
    solve();
  }
}