#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n , m , r , c; cin >> n >> m >> r >> c;
    cout << (m - c) + (n - r)*((2 * m) - 1) << endl;
}

int main(){
  ll t; cin >> t;
  while(t--){
    solve();
  }
}