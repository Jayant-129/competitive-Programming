#include<bits/stdc++.h>
using namespace std;
#define ll long long
unordered_map<ll,ll> mp;

ll count(ll x){
    if(x == 0) return 1;
    ll digits = 0;
    while(x > 0){
        digits++;
        x /= 10;
    }
    return digits;
}

ll solve(ll x,ll n){
    ll y = count(x);
    if(y == n){
        return 0;
    }
    if(y > n || x == 0){
        return INT_MAX;
    }
    if(mp.find(x) != mp.end()){
        return mp[x];
    }
    y = x;
    ll ans = INT_MAX;
    while(y > 0){
        ll z = y % 10;
        y /= 10;
        if(z == 0 || z == 1) continue;
        ans = min(ans,1 + solve(x*z,n));
    }
    return mp[x] = ans;
}

int main(){
   mp.reserve(1024);
   mp.max_load_factor(0.25);
  ll n , x; cin >> n >> x;
  if(x == 1 && n > 1){
    cout << -1 << endl;
  }
  else{
    ll val = solve(x,n);
    if(val == INT_MAX){
        cout << -1 << endl;
        return 0;
    }
    cout << solve(x,n) << endl;
  }
}