#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n; cin >> n;
    map<ll,ll> mp;
    vector<ll> v(n); for(auto& x: v) cin >> x;
    vector<ll> dp(n,0);
    mp[v[0]] = 0;
    dp[0] = 0;
    for(ll i = 1; i < n; i++){
        dp[i] = dp[i-1]; 
        if(mp.find(v[i]) == mp.end()){
            mp[v[i]] = i;
        }
        else{
            ll prev = mp[v[i]];
            if(dp[prev] == 0 || dp[prev] == dp[prev - 1]){
                dp[i] = max(dp[i], i - prev + 1 + (prev > 0 ? dp[prev]: 0));
            }
            else{
                dp[i] = max(dp[i], i - prev + (prev > 0 ? dp[prev]: 0));
            }
            if(dp[i] > dp[prev]){
                mp[v[i]] = i;
            }
        }
    }
    cout << dp[n - 1] << endl;
}

int main(){
  ll t; cin >> t;
  while(t--){
    solve();
  }
}