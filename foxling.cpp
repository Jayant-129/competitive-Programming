#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<vector<ll>> dp;
const int M = 1e9 + 7;
ll f(ll i, ll m, vector<pair<ll,ll>>& v){
    if(i == 0 && m == 0){
        return 1;
    }
    if(i == 0 || m <= 0){
        return 0;
    }
    if(dp[i][m] != -1){
        return dp[i][m];
    }
    ll st = v[i].first;
    ll en = v[i].second;
    ll ans = 0;
    for(int j = st; j <= en; j++){
        ans = (ans + f(i - 1,m - j,v)) % M;
    }
    return dp[i][m] = ans;
}
void solve(){
    ll n , m; cin >> n >> m;
    dp.clear();
    dp.resize(n + 1,vector<ll>(m + 1, -1));
    vector<pair<ll,ll>> v(n + 1);
    for(int i = 1; i <= n; i++){
        ll x , y; cin >> x >> y;
        v[i] = {x,y};
    }
    cout << f(n,m,v) << endl;
}
int main(){
  ll t; cin >> t;
  while(t--){
    solve();
  }
}