#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> ans(n + 1, 0);
    ll curr = 1;
    for(ll i = k; i <= n; i += k) {
        ans[i] = curr++;
    }
    for(ll i = 1; i <= n; i++) {
        if(ans[i] == 0) {
            ans[i] = curr++;
        }
    }
    for(ll i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}

int main(){
  ll t; cin >> t;
  while(t--){
    solve();
  }
}