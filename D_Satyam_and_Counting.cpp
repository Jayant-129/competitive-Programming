#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n; cin >> n;
    vector<ll> v(n + 1,0); set<pair<ll,ll>> s;ll cnt = 0;
    for(int i = 0; i < n; i++){
        ll x, y; cin >> x >> y; s.insert({x,y}); v[x]++;
    }
    // for(int i = 0; i <= n; i++){
    //     cout << i << ":" << v[i] << " ";
    // }
    for(int i = 0; i <= n; i++){
        if(v[i] == 2){
            cnt += (n - 2);
        }
    }
    //cout << cnt << endl;
    for(auto& k: s){
        auto i = k.first;
        auto j = k.second;
        auto it = s.find({i + 1, !j});
        auto it2 = s.find({i - 1, !j});
        if(it != s.end() && it2 != s.end()){
            cnt++;
        }
        //cout << cnt << endl;
    }
    cout << cnt << endl;
}

int main(){
  ll t;
  cin >> t;
  while(t-- > 0) solve();
}