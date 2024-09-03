#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll> v;
vector<ll> dp;
void solve(){
    ll n, k; cin >> n >> k;
    vector<ll> pre(n + 1,0);
    dp.resize(n + 4,0);
    v.resize(n + 1,0);
    pre[0] = 0;

    for(int i = 1; i <= n; i++){
        ll x; cin >> x;
        v[i] = x;
        pre[i] = x;
        if(i) pre[i] += pre[i - 1];
    }
    for(int i = n; i > 0; i--){
        if(v[i] <= k){
            auto it = upper_bound(pre.begin(),pre.end(), pre[i - 1] + k);
            int idx = distance(pre.begin(),it);
            dp[i] = dp[idx + 1] + (idx - i);
        }
        else{
            dp[i] = dp[i + 1];
        }
    }
    ll ans = 0;
    for(int i = 1; i <= n; i++){
        ans += (dp[i]);
    }
    cout << ans << endl;
    dp.clear();
    v.clear();
}

int main(){
  ll t; cin >> t;
  while(t--){
    solve();
  }
}