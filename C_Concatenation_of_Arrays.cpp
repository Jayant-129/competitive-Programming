#include<bits/stdc++.h>
using namespace std;
#define ll long long

bool comp(const pair<ll,ll> p1,const pair<ll,ll> p2){
    if(max(p1.first,p1.second) == max(p2.first,p2.second)){
        return min(p1.first,p1.second) < min(p2.first,p2.second);
    }
    return max(p1.first,p1.second) < max(p2.first,p2.second);
}

void solve(){
    ll n; cin >> n;
    vector<pair<ll,ll>> v;
    for(int i = 0; i < n; i++){
        ll x,y; cin >> x >> y;
        v.push_back({x,y});
    }
    sort(v.begin(),v.end(),comp);
    for(auto& i: v){
        cout << i.first << " " << i.second << " ";
    }
    cout << endl;
}

int main(){
  ll t; cin >> t;
  while(t--){
    solve();
  }
}