#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n; cin >> n; vector<ll> v(n), b(n);
    for(auto& x: v) cin >> x;
    for(auto& x: b) cin >> x;
    int s = 0;
    for(int i = 0; i < n - 1; i++){
        if(v[i] > b[i + 1]){
            s += (v[i] - b[i + 1]);
        }
    }
    s += (v[n - 1]);
    cout << s << endl;
}

int main(){
  ll t; cin >> t;
  while(t--){
    solve();
  }
}