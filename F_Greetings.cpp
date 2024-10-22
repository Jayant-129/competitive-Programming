#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
typedef tree<int, null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> ordered_set;
vector<pair<ll,ll>> v;
vector<ll> v1;
ordered_set s;
bool comp(const pair<ll,ll> p1, pair<ll,ll> p2){
  return p1.first < p2.first;
}
void solve(){
    ll n; cin >> n; v.resize(n); v1.resize(n);
    for(int i = 0; i < n; i++){
        ll x , y; cin >> x >> y;
        v[i] = {x,y};
    }
    sort(v.begin(),v.end(),comp);
    for(int i = 0; i < n; i++){
        v1[i] = v[i].second;
    }
    ll cnt = 0;
    for(int i = 0; i < n; i++){
        ll val = s.order_of_key(v1[i]);
        cnt += (s.size() - val);
        s.insert(v1[i]);
    }
    cout << cnt << endl;
    s.clear();
    v1.clear();
    v.clear();
}

int main(){
  ios::sync_with_stdio(0);cin.tie(0);
  ll t; cin >> t;
  while(t--){
    solve();
  }
}