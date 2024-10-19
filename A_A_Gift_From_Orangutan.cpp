#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n; cin >> n;
    vector<ll> v(n,0);
    for(auto& x: v) cin >> x;
    ll maxi = INT_MIN, mini = INT_MAX;
    for(auto& i: v){
        maxi = max(i,maxi);
        mini = min(i,mini);
    }
    cout << (n - 1)* (maxi - mini) << endl;
}

int main(){
  ll t; cin >> t;
  while(t--){
    solve();
  }
}