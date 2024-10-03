#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll a, b , n; cin >> a >> b >> n;
    unordered_map<ll , ll> ump , ump1;
    vector<pair<int,int>> v(n, {0 , 0});
    for(int i = 0; i < n; i++){
        ll x; cin >> x;
        ump[x]++;
        v[i] = {x,0};
    }
    for(int i = 0; i < n; i++){
        ll x; cin >> x;
        ump1[x]++;
        v[i] = {v[i].first, x};
    }
    ll ans = 0;
    for(auto& i: v){
        ll j = i.first;
        ll k = i.second;
        ll val = ump[j] + ump1[k] - 2;
        ans += (n - val - 1);
    }
    cout << ans/2 << endl;
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  ll t;cin >> t;
  while(t-- > 0){
    solve();
  }
}