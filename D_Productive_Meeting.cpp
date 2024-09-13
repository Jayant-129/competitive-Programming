#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n;cin >> n;priority_queue<pair<ll,ll>,vector<pair<ll,ll>>> pq;
    for(int i = 1; i <= n; i++){
        ll x;cin >> x;
        if(x > 0){
            pq.push({x,i});
        }
    }
    vector<pair<int,int>> v;
    ll cnt = 0;
    while(pq.size() > 1){
        auto curr = pq.top();pq.pop();
        auto next = pq.top();pq.pop();
        curr.first--;
        next.first--;
        v.push_back({curr.second,next.second});
        if(curr.first > 0) pq.push({curr.first,curr.second});
        if(next.first > 0) pq.push({next.first,next.second});
    }
    cout << v.size() << endl;
    for(auto& i:v){
       cout << i.first << " " << i.second << endl;
    }
}

int main(){
  ios::sync_with_stdio(0);cin.tie(0);
  ll t;
  cin >> t;
  while(t-- > 0){
    solve();
  }
}