#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n; cin >> n;
    map<ll,ll> mp;
    for(int i = 0; i < n; i++){
        ll x;  cin >> x;
        mp[x]++;
    }
    ll ans = 0;
    for(auto& i: mp){
        ans += (i.second/2);
    }
    cout << ans << endl;
}

int main(){
  ll t; cin >> t;
  while(t--){
    solve();
  }
}