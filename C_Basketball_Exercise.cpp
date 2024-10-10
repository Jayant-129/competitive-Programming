#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<vector<ll>> dp;
vector<ll> v , v1;
ll dpsolve(ll i,ll k){
    if(i < 0){
        return 0;
    }
    if(dp[i][k] != -1){
        return dp[i][k];
    }
    ll ans = dpsolve(i - 1,0);
    if(k == 1){
        ans = max(ans,v1[i] + dpsolve(i - 1,2));
    }
    else if(k == 2){
        ans = max(ans,v[i] + dpsolve(i - 1,1));
    }
    else{
        ans = max(ans,v1[i] + dpsolve(i - 1,2));
        ans = max(ans,v[i] + dpsolve(i - 1,1));
    }
    dp[i][k] = ans;
    return ans;
}

int main(){
  ll n; cin >> n;
  v.resize(n, 0);
  v1.resize(n, 0);
  for(int i = 0; i < n; i++) cin >> v[i];
  for(int i = 0; i < n; i++) cin >> v1[i];
  dp.resize(n,vector<ll>(3,-1));
  cout << dpsolve(n - 1, 0) << endl;
}