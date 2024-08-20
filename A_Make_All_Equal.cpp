#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n;
    cin >> n;
    map<ll,ll> mp;
    ll maxi = 0;
    for(ll i = 0; i < n; i++){
        ll x;
        cin >> x;
        mp[x]++;
        maxi = max(maxi, mp[x]);
    }
    cout << n - maxi << endl;
}

int main(){
  ll t;
  cin >> t;
  while(t-- > 0){
    solve();
  }
}