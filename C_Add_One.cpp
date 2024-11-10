#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll M = 1e9 + 7;
  vector<vector<ll>> dp;
void solve(){
    ll n, m ; cin >> n >> m;
    ll sum = 0;
    while(n > 0){
        ll x = n  % 10;
        sum = (sum + dp[m][x])%M;
        n /= 10; 
    }
    cout << sum << endl;
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  dp.resize(200005,vector<ll>(10,0));
  for(int i = 0; i < 10; i++){
    dp[0][i] = 1;
  }
  for(int i = 1; i < 200005; i++){
    for(int j = 0; j < 10; j++){
        if(j < 9){
            dp[i][j] = (dp[i][j] + dp[i - 1][j + 1])%M;
        }
        else{
            dp[i][j] = (dp[i][j] +  (dp[i - 1][1] + dp[i - 1][0]) % M) % M;
        }
    }
  }
  ll t; cin >> t;
  while(t--){
    solve();
  }
}