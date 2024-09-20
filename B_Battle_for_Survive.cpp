#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n; cin >> n; vector<ll> v(n, 0); for(auto& x: v) cin >> x;
    ll sum = 0;
    for(int i = 0; i < (n-2); i++){
        sum += v[i];
    }
    cout << v[n-1] + sum - v[n - 2] << endl;
}

int main(){
  ll t;
  cin >> t;
  while(t-- > 0){
    solve();
  }
}