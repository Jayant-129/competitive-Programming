#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<vector<ll>> dp;
vector<ll> v;
ll dpsolve(ll i, ll prev){
    if(i < 0){
        return 0;
    }
    if(dp[i][prev] != -1){
        return dp[i][prev];
    }
    ll curr = v[i];
    ll ans = INT_MAX;
    if(curr == 0){
        ans = 1 + dpsolve(i - 1,0);
    }
    else if(curr == 1){
        if(prev != 1){
            ans = dpsolve(i - 1,1);
        }
        ans = min(1 + dpsolve(i - 1, 0),ans);
    }
    else if(curr == 2){
        if(prev != 2){
            ans = dpsolve(i - 1,2);
        }
        ans = min(1 + dpsolve(i - 1, 0),ans);
    }
    else{
        ans = 1 + dpsolve(i - 1, 0);
        if(prev != 1){
            ans = min(dpsolve(i - 1,1),ans);
        }
        if(prev != 2){
            ans = min(dpsolve(i - 1,2),ans);
        }
    }
    return dp[i][prev] = ans;
}
int main(){
  ll n;
  cin >> n;
  v.resize(n, 0);
  for(auto& x: v) cin >> x;
  dp.resize(n,vector<ll>(4,-1));
  cout << dpsolve(n - 1,0) << endl;
}