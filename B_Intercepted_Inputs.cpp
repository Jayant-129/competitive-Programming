#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    ll n; cin >> n;
    map<ll,ll> mp;
    for(int i = 0; i < n; i++){
        ll x; cin >> x;
        mp[x]++;
    }
    ll k = n - 2;
    for(int i = 1; i <= k; i++){
        if(k % i == 0){
            if(k/i == i && mp[i] >= 2){
                cout << i << " " << i << endl;
                break;
            }
            else if(k/i != i && mp[i] && mp[k/i]){
                cout << k/i << " " << i  << endl;
                break;
            }
        }
    }
}
int main(){
  ll t; cin >> t;
  while(t--){
    solve();
  }
}