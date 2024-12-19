#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n; cin >> n;
    map<ll,ll> mpx,mpy,mpxy,mpyx;
    for(int i = 0; i < n; i++){
        ll x, y; cin >> x >> y;
        mpx[x]++; mpy[y]++; mpxy[x - y]++;
        mpyx[y + x]++;
    }
    ll ans = 0;
    for(auto& i: mpx){
        ll val = i.second;
        ans += (val * (val - 1));
    }
    for(auto& i: mpy){
        ll val = i.second;
        ans += (val * (val - 1));
    }
    for(auto& i: mpxy){
        ll val = i.second;
        ans += (val * (val - 1));
    }
    for(auto& i: mpyx){
        ll val = i.second;
        ans += (val * (val - 1));
    }
    cout << ans << endl;
}

int main(){
  ll t; cin >> t;
  while(t--){
    solve();
  }
}