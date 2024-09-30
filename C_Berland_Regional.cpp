#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n; cin >> n;
    vector<pair<ll,ll>> v(n,{0,0});
    for(int i = 0; i < n; i++){
        ll x; cin >> x;
        v[i].first = x - 1;
    }
    for(int i = 0; i < n; i++){
        ll y; cin >> y;
        v[i].second = y;
    }
    vector<vector<ll>> v1(n);;
    for(auto& i:v){
        v1[i.first].push_back(i.second);
    }
    for(int i = 0; i < n; i++){
        sort(v1[i].begin(),v1[i].end(),greater<ll>());
        for(int j = 1; j < v1[i].size(); j++){
            v1[i][j] = v1[i][j] + v1[i][j - 1]; 
        }
    }
    vector<ll> ans(n + 1,0);
    for(int i = 0; i < n; i++){
        ll s = v1[i].size();
        for(int j = 1; j <= s; j++){
            ans[j] += (v1[i][(s-1) - (s)%j]);
        }
    }
    for(int i = 1; i <= n; i++){
        cout << ans[i] << " ";
    }
    cout << endl;
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  ll t;
  cin >> t;
  while(t-- > 0){
    solve();
  }
}