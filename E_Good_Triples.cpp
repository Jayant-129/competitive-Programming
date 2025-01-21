#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n; cin >> n;
    vector<ll> v(10,0);
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            for(int k = 0; k < 10; k++){
                if(i + j + k < 10){
                    v[i + j + k]++;
                }
            }
        }
    }
    ll ans = 1;
    while(n > 0){
        ll x = n % 10;
        ans *= v[x];
        n /= 10;
    }
    cout << ans << endl;
}
int main(){
  ll t; cin >> t;
  while(t--){
    solve();
  }
}