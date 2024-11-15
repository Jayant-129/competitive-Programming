#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n; cin >> n;
    vector<ll> v(n , 0); for(auto& x:v) cin >> x;
    vector<ll> v1(n , 0); for(auto& x:v1) cin >> x;
    vector<ll> v2(n , 0); for(auto& x:v2) cin >> x;
    vector<ll> dp(n, 0); dp[1] = v[1] + abs(v2[1] - v1[1]) + 1;
    for(int i = 2; i < n; i++){
        ll a = min(v1[i],v2[i]) , b = max(v1[i],v2[i]);
        if(a == b){
            dp[i] = 1 + v[i];
        }
        else{
            ll val1 = v[i] + (b - a) + 1;
            ll val2 = v[i] + dp[i - 1] + a + 1 - b;
            dp[i] = max(val1, val2);
        }
    }
    ll maxi = 0;
    for(auto& i: dp){
        maxi = max(maxi,i);
    }
    cout << maxi << endl;
}

int main(){
  ll t; cin >> t;
  while(t--){
    solve();
  }
}