#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll f(ll x, ll y){
    ll ans;
    cout << "? " << x << " " << y << endl;
    cin >> ans;
    cout.flush();
    return ans;
}
void solve(){
    ll r, c; cin >> r >> c;
    ll m = f(1,1);
    m++;
    if(r >= m){
        ll m2 = f(m,1);
        if(1 + m2 < m){
            cout << "!" << " " << m << " " << 1 + m2 << endl;
            return;
        }
        else{
            ll m3 = f(1,m);
            cout << "!" << " " << 1 + m3 << " " << m << endl;
        }
    }
    else{
         ll m3 = f(1,m);
        cout << "!" << " " << 1 + m3 << " " << m << endl;
    }
}
int main(){
  ll t; cin >> t;
  while(t--){
    solve();
  }
}