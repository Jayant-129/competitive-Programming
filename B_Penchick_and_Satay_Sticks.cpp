#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n; cin >> n;
    vector<ll> v(n,0); for(auto& x: v) cin >> x;
    ll maxi = 0; bool flag = false;
    for(int i = 0; i < n; i++){
        ll val = maxi - v[i];
        if(val >= 2){
            flag = true;
            break;
        }
        maxi = max(maxi,v[i]);
    }
    if(flag){
        cout << "NO" << endl;
    }
    else{
        cout << "YES" << endl;
    }
}

int main(){
  ll t; cin >> t;
  while(t--){
    solve();
  }
}