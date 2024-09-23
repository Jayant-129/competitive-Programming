#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll> dp;
ll solve(vector<ll>& v, ll i){
    if(i == 0) return 0;
    if(i == 1) return v[1];
    if(dp[i] != -1){
        return dp[i];
    }
    ll ans = max(solve(v, i - 1),solve(v,i - 2) + i * v[i]);
    return dp[i] = ans;
}
int main(){
  ll n; cin >> n;
  vector<ll> v(n,0);
  ll maxi = INT_MIN;
  for(int i = 0; i < n; i++){
    cin >> v[i];
    maxi = max(v[i], maxi);
  }
  vector<ll> cnt(maxi + 1, 0);
  for(auto& i: v){
    cnt[i]++;
  }
  dp.resize(maxi + 1,-1);
  cout << solve(cnt,maxi) << endl;
}