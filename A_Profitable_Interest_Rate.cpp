#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll a , b;cin >> a >> b;
    if(a >= b){
        cout << a << endl;
    }
    else{
        ll ans = (2 * a - b);
        if(ans > 0){
            cout << ans << endl;
        }
        else{
            cout << 0 << endl;
        }
    }
}

int main(){
  ll t; cin >> t;
  while(t-- > 0){
    solve();
  }
}