#include<bits/stdc++.h>
using namespace std;
#define ll long long

pair<ll,ll> f(ll i, ll k){
    if(i < k){
        return {0,0};
    }
    if(i % 2 == 0){
        auto ans = f(i/2,k);
        return {(2 * ans.first) + (ans.second * (i/2)), ans.second * 2};
    }
    auto ans = f(i/2,k);
    ll mid = (i + 1)/2;
    return {2 * ans.first + (ans.second * (i/2 + 1)) + mid, ans.second * 2 + 1};
    
}

void solve(){
    ll n, k;
    cin >> n >> k;
    cout << f(n,k).first << endl;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll t; cin >> t;
  while(t--){
    solve();
  }
}