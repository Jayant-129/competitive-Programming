#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll> v;
bool good(ll mid, ll k){
    ll n = v.size();
    for(int i = 0; i < n; i++){
        vector<ll> mini(n);
        ll cnt = 0;
        mini[i] = mid;
        for(int j = i; j < n; j++){
            if(mini[j] <= v[j]) break;
            if(j + 1 >= n){
                cnt = k + 1;
                break;
            }
            cnt += (mini[j] - v[j]);
            mini[j + 1] = max(0LL,mini[j] - 1);
        }
        if(cnt <= k){
            return true;
        }
    }
    return false;
}
void solve(){
    ll n , k; cin >> n >> k;
    v.resize(n);
    for(auto& x: v) cin >> x;
    ll l = *max_element(v.begin(),v.end()),  r = 1e9;
    while(l + 1 < r){
        ll mid = l + (r - l)/2;
        if(good(mid,k)){
            l = mid;
        }
        else{
            r = mid;
        }
    }
    cout << l << endl;
    v.clear();
}
int main(){
  ll t; cin >> t;
  while(t--){
    solve();
  }
}