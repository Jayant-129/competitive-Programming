#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n, m ,x; cin >> n >> m >> x;
    vector<ll> v(n,0); for(auto& x: v) cin >> x;
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
    for(int i = 1; i <= m; i++) pq.push({0,i});
    cout << "YES" << endl;
    for(auto& i: v){
        auto curr = pq.top();
        pq.pop();
        pq.push({curr.first + i, curr.second});
        cout << curr.second << " ";
    }
    cout << endl;
}
int main(){
  ll t; cin >> t;
  while(t--){
    solve();
  }
}