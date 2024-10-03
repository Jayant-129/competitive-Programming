#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n; cin >> n; vector<pair<int,int>> v(n);
    for(int i = 0; i < n; i++){
        ll x; cin >> x;
        v[i] = {x,i};
    }
    vector<ll> pre(n,0);
    sort(v.begin(),v.end());
    for(int i = 0; i < n; i++){
        pre[i] = v[i].first;
        if(i) pre[i] += pre[i - 1]; 
    }
    ll prev = -1;
    for(int i = 0; i < (n - 1); i++){
        if(pre[i] < v[i + 1].first){
            prev = i;
        }
    } 
    vector<ll> ans;
    for(int i = prev + 1; i < n; i++){
        ans.push_back(v[i].second);
    }
    sort(ans.begin(),ans.end());
    cout << ans.size() << endl;
    for(auto& i: ans){
        cout << i + 1 << " ";
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