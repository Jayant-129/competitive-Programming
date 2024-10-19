#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll h,n;
vector<ll> v;
vector<ll> c;
bool good(ll mid){
    mid--;
    ll cnt = 0;
    for(int i = 0; i < v.size(); i++){
        cnt += ((mid/c[i])*v[i] + v[i]);
        if(cnt >= h) break;
    }
    return h <= cnt;
}
void solve(){
    cin >> h >> n;
    v.resize(n); for(auto& x: v) cin >> x;
    c.resize(n); for(auto& x: c) cin >> x;
    ll sum = 0; for(auto& x: v) sum += x;
    if(sum >= h){
        cout << 1 << endl;
        return;
    }
    ll l = 1; ll r = 1e12;
    while(l + 1 <  r){
        ll mid = l + (r - l)/2;
        if(good(mid)){
            r = mid;
        }
        else{
            l = mid;
        }
    }
    cout << r << endl;
    v.clear();
}

int main(){
  ll t; cin >> t;
  while(t--){
    solve();
  }
}