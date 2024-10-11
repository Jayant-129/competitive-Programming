#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
vector<ll> dp(100005,-1);
vector<ll> pre(100005,0);
ll k;
ll dpsolve(ll i){
    if(i > 100000){
        return 0;
    }
    if(i == 100000){
        dp[i] = 1;
        return 1;
    }
    if(dp[i] != -1) return dp[i];
    ll ans = 0;
    ans = ans + ((dpsolve(i + k) + dpsolve(i + 1)) % MOD);
    return dp[i] = ans;
}
int main(){
  ll t;
  cin >> t;
  cin >> k;
  dpsolve(0);
  for(int i = 100000; i >= 0; i--){
    ll val = 100000 - i;
    pre[val] = dp[i];
    if(val) pre[val] = (pre[val] + pre[val - 1]) % MOD;
  }
  ll a , b;
  while(t--){
    cin >> a >> b;
    cout << (pre[b] - pre[a - 1] + MOD) % MOD << endl;
  }
}