#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll M = 1e9 + 7;
ll dp[101][100001];

int main(){
  ll n , k; cin >> n >> k; vector<int> v(n); for(int i = 0; i < n; i++) cin >> v[i];
  for(int i = 0; i < k +1; i++){
    if(i <= v[0]){
        dp[0][i] = 1;
    }
    else{
        dp[0][i] = 0;
    } 
  }
  for(int i = 1; i < n; i++){
    vector<ll> pre(k + 1); pre[0] = dp[i - 1][0];
    for(int j = 1; j < k + 1; j++){
        pre[j] = (pre[j - 1] + dp[i - 1][j]) % M;
    }
    for(int j = 0; j < k + 1; j++){
       if(j > v[i]){
          dp[i][j] = (pre[j] + M - pre[j - v[i] - 1]) % M;
       }
       else{
         dp[i][j] = pre[j];
       }
    }
  }
  cout << dp[n - 1][k] << endl;
}