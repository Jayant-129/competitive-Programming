#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n , k; cin >> n >> k; vector<ll> v(n,0); for(auto& x: v) cin >> x;
    ll r = 0; ll cnt = 0;
    for(int i = 0; i < n; i++){
        if(v[i] >= k){
            r += v[i];
        }
        else if(v[i] == 0){
            if(r > 0){
                cnt++;
                r -= 1;
            }
        }
    }
    cout << cnt << endl;
}

int main(){
  ll t;
  cin >> t;
  while(t-- > 0){
    solve();
  }
}