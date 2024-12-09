#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll M = 1e9 + 7;
vector<ll> dp(300007, -1);

int main(){
  dp[0] = 1;
  dp[1] = 1;
  dp[2] = 3;
  for(int i = 3; i <= 300000; i++){
    dp[i] = (dp[i - 1] + ((2 * (i - 1)) * dp[i - 2]) % M) % M;
  }
  ll t; cin >> t;
  while(t--){
    ll n , k; cin >> n >> k;
    ll cnt = 0;
    for(int i = 0; i < k; i++){
        ll x, y; cin >> x >> y;
        if(x == y){
            cnt++;
        }
        else{
            cnt += 2;
        }
    }
    cout << dp[n - cnt] << endl;
  }
}