#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll M = 1e9 + 7;
void solve(){
    ll n; cin >>n;
    ll prev = 1, remain = n, ans = 0, lcm = 1;
    for(ll i = 2; i <= 100; i++){
        ll g = (ll)(__gcd(lcm,i));
        lcm = ((lcm * i)/g);
        ll val = (remain - (n/lcm));
        ans = (ans + (val * i) % M) % M;
        remain = (n/lcm);
        if(remain == 0){
            break;
        }
    }
    cout << ans << endl;
}

int main(){
  ll t; cin >> t;
  while(t--){
    solve();
  }
}