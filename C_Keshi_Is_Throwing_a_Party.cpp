#include<bits/stdc++.h>
using namespace std;
#define ll long long

bool good(ll mid,vector<pair<ll,ll>>& v){
    ll k = 0;
    for(int i = 0; i < v.size(); i++){
        ll val = mid - k - 1;
        if(v[i].first >= val && v[i].second >= k){
            k++;
        }
    }
    return k >= mid;
}

void solve(){
    ll n; cin >> n;
    vector<pair<ll,ll>> v(n);
    for(int i = 0; i < n; i++){
        ll x , y; cin >> x >> y;
        v[i] = {x,y};
    }
    ll l = 0 , r = (n + 1);
    while(l + 1 < r){
        ll mid = l + (r - l)/2;
        if(good(mid,v)){
            l = mid;
        }
        else{
            r = mid;
        }
    }
    cout << l << endl;
}

int main(){
  ll t; cin >> t;
  while(t--){
    solve();
  }
}