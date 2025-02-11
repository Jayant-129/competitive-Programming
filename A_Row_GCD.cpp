#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n, m; cin >> n >> m;
    vector<ll> a(n,0); for(auto& x: a) cin >> x;
    vector<ll> b(m, 0); for(auto& x: b) cin >> x;
    if(a.size() > 1){
        sort(a.begin(), a.end());
        vector<ll> v(n - 1, 0);
        for(int i = 0; i < n - 1; i++){
            v[i] = (abs(a[i]- a[i + 1]));
        }
        ll val = v[0];
        for(int i = 1; i < v.size(); i++){
            val = __gcd(val,v[i]);
        }
        for(int i = 0; i < m; i++){
            cout << __gcd(val, a[0] + b[i]) << " ";
        }
        cout << endl;
    }
    else{
        for(int i = 0; i < m; i++){
            cout << a[0] + b[i] << endl;
        }
    }
}

int main(){
  ll t = 1;
  while(t--){
    solve();
  }
}