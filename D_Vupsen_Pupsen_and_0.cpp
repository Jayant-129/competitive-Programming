#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n; cin >> n;
    vector<ll> v(n, 0);
    for(auto& x: v) cin >> x;
    ll beg = 0;
    if(n % 2){
        if(v[0] != -v[1]){
            ll val = abs(v[0] + v[1]);
            ll val2 = abs(v[2]);
            ll lcm = ((val*val2)/(__gcd(val,val2)));
            ll x = lcm/(v[0] + v[1]) , y = lcm/v[2];
            cout << -x << " " << -x << " " << y << " ";
        }
        else{
            ll val = abs(v[0]) + abs(v[1]);
            ll val2 = abs(v[2]);
            ll lcm = ((val*val2)/(__gcd(val,val2)));
            ll x = lcm/val , y = lcm/v[2];
            if(v[0] > 0) cout << x << " ";
            else cout << -x << " ";
            if(v[1] > 0) cout << x << " ";
            else cout << -x << " ";
            cout << -y << " ";
        }
        beg = 3;
        
    }
    for(int i = beg; i < n; i += 2){
        ll val = abs(v[i]);
        ll val2 = abs(v[i + 1]);
        ll lcm = ((val*val2)/(__gcd(val,val2)));
        ll x = lcm/v[i], y = lcm/v[i + 1];
        cout <<  -x << " " << y << " ";
    }
    cout << endl;
}

int main(){
  ll t; cin >> t;
  while(t--){
    solve();
  }
}