#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n , q; cin >> n >> q;
    map<ll,ll> mp;
    vector<ll> v(n , 0);
    for(ll i = 0; i < n; i++){
        cin >> v[i];
        ll val = (i + 1)* (n - i) - 1;
        mp[val]++;
    }
    for(ll i = 0; i < n - 1; i++){
        ll val = (i + 1)*(n - i - 1);
        mp[val] += (v[i + 1] - v[i] - 1);
    }
    for(ll i = 0; i < q; i++){
        ll x; cin >> x;
        cout << mp[x] << " ";
    }
    cout << endl;
}


int main(){
  ios::sync_with_stdio(0);cin.tie(0);
  ll t;
  cin >> t;
  while(t-- > 0){
    solve();
  }
}