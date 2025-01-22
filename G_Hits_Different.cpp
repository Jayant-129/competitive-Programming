#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll> dp(1000005,0);
void solve(){
    ll n; cin >> n;
    cout << dp[n] << endl;
}

int main(){
  dp[1] = 1;
  ll r = 3, k = 2, prev = 1;
  for(ll i = 2; i < 1000001; i++){
    dp[i] = i * i;
    if(i != (prev + 1)){
        dp[i] += dp[i - k];
    }
    if(i != r){
        dp[i] += dp[i - k + 1];
    }
    if(i != (prev + 1) && i != r){
        dp[i] -= dp[i - 2 * k + 2];
    }
    if(i == r){
        prev = r;
        k++;
        r += k;
    }
  }
  ll t; cin >> t;
  while(t--){
    solve();
  }
}