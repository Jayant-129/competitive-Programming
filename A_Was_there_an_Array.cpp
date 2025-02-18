#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n; cin >> n; vector<ll> v(n - 2, 0);
    for(auto& i: v) cin >> i;
    
    for(int i = 1; i < (v.size() - 1); i++){
        if(v[i - 1] == 1 && v[i] == 0 && v[i + 1] == 1){
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

int main(){
  ll t; cin >> t;
  while(t--){
    solve();
  }
}