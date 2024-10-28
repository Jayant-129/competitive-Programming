#include<bits/stdc++.h>
using namespace std;
#define ll long long 
void solve(){
    ll a , b , k;
    cin >> a >> b >>k;
    ll val = min(a,b);
    cout << 0 << " " << 0 << " " << val << " " << val << endl;
    cout << 0 << " "  << val  << " " << val  << " " << 0 << endl;
}
int main(){
  ll t; cin >> t;
  while(t--){
    solve();
  }
}