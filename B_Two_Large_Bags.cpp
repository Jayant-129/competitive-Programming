#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n; cin >> n; vector<ll> v(1001, 0);
    for(int i = 0; i < n; i++){
        ll x; cin >> x;
        v[x]++;
    }
    for(int i = 1; i <= 999; i++){
        if(v[i] == 0) continue;
        if(v[i] == 1){
            cout <<  "No" << endl;
            return;
        }
        v[i + 1] += (v[i] - 2);
    }
    if(v[1000] % 2){
        cout << "No" << endl; 
        return;
    }
    cout << "Yes" << endl;
}

int main(){
  ll t; cin >> t;
  while(t--){
    solve();
  }
}