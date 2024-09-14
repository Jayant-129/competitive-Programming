#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
  ios::sync_with_stdio(0);cin.tie(0);
  ll n; cin >> n;
  vector<ll> v(n, 0); vector<ll> pre(n,0);
  for(ll i = 0; i < n; i++) cin >> v[i];
  for(ll i = 0; i < n; i++){
    ll x;
    cin >> x;
    pre[i] = x;
    if(i) pre[i] += pre[i -1];
  }
  ll q;cin >> q;
  for(ll i = 0; i < q; i++){
    ll x , y; cin >> x >> y;
    auto it = lower_bound(v.begin(),v.end(),x);
    if(it == v.end()){
        cout << 0 << endl;
        continue;
    }
    ll idx1 = distance(v.begin(),it);
    auto it2 = upper_bound(v.begin(),v.end(),y);
    if(it2 == v.begin()){
        cout << 0 << endl;
        continue;
    }
    ll idx2 = distance(v.begin(),it2); idx2--;
    ll val = pre[idx2];
    if(idx1) val -= pre[idx1 - 1];
    cout << val << endl;
  }
}