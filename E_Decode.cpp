#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 1e9 + 7;
void solve(){
    string s; cin >> s;
    ll curr = 0;
    map<ll,ll> mp;
    int n = s.size();
    mp[0] = 1;ll ans = 0;
    for(int i = 0; i < n; i++){
        curr += ((s[i] == '1')? 1 : -1);
        ans = (ans + ((mp[curr]) * (n - i)) % MOD) % MOD;
        mp[curr] += (i + 2);
    }
    cout << ans << endl;
}
int main(){
  ll t; cin >> t;
  while(t--){
    solve();
  }
}
