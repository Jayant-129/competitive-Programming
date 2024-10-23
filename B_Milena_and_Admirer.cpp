#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n; cin >> n;
    vector<ll> v(n , 0);
    for(auto& x: v) cin >> x;
    ll prev = INT_MAX, cnt = 0;
    for(int i = n - 1; i >= 0 ; i--){
        ll curr = v[i];
        if(prev >= curr){
            prev = curr;
        }
        else{
            ll k = ceil(double(curr)/prev);
            cnt += (k - 1);
            prev = (floor(double(curr)/k));
        }
    }
    cout << cnt << endl;
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  ll t; cin >> t;
  while(t--){
    solve();
  }
}