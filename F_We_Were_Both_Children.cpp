#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    ll n;
    cin >> n;
    map<ll,ll> mp;
    for(ll i = 0; i < n; i++){
        ll x;
        cin >> x;
        mp[x]++;
    }
    vector<ll> ans(n + 1,0);
    for(auto& [i,k]: mp){
        for(ll j = i; j <= n; j += i){
            ans[j] = ans[j] + (k);
        }
    }
    ll maxi = 0;
    for(ll i = 1; i <= n; i++){
        maxi = max(maxi,ans[i]);
    }
    cout << maxi << endl;
}

int main(){
  ios::sync_with_stdio(0);cin.tie(0);
  ll t;
  cin >> t;
  while(t-- > 0){
    solve();
  }
}