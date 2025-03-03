#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n; cin >> n;
    vector<ll> v(n); vector<ll> a;for(auto& x: v) cin >> x;
    vector<ll> suff;
    vector<ll> pref;
    unordered_map<ll,ll> mp;
    for(auto& i: v){
        mp[i]++;
    }
    for(auto [i,j]: mp){
        a.push_back(j);
    }
    sort(a.begin(),a.end());
    suff.resize(a.size(),0);
    pref.resize(a.size(),0);
    for(int i = a.size() - 1; i >= 0; i--){
        suff[i] += a[i];
        if(i < a.size() - 1) suff[i] += suff[i + 1];
    }
    for(int i = 0; i < a.size(); i++){
        pref[i] += a[i];
        if(i) pref[i] += pref[i - 1];
    }
    ll mini = LLONG_MAX;
    for(int i = 1; i <= n; i++){
        auto it = lower_bound(a.begin(),a.end(),i);
        ll ans = 0;
        if(it == a.end()){
            ans = pref[a.size() - 1];
            mini = min(ans,mini);
            continue;
        }
        ll idx = distance(a.begin(),it);
        if(idx > 0){
            ans += pref[idx - 1];
        }
        ans += (suff[idx] - (i * (a.size() - idx)));
        //cout << ans << endl;
        mini = min(mini,ans);
    }
    cout << mini << endl;
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll t; cin >> t;
  while(t--){
    solve();
  }
}