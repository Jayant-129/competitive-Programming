#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n,k; cin >> n >> k;
    vector<ll> v(n, 0); for(auto& x: v) cin >> x;
    ll idx = -1;
    for(int i = 1; i < n; i++){
        if(v[i] != 1){
            idx = i;
            break;
        }
    }
    if(idx == -1){
        cout << 2 << endl;
        return;
    }
    if(k == n){
        ll z = 1;
        for(int i = 1; i < n; i+=2){
            if(v[i] != z){
                cout << z  << endl;
                return;
            }
            z++;
        }
        cout << z << endl;
        return;
    }
    if((n - (idx+1)) >= (k - 2)){
        cout << 1 << endl;
        return;
    }
    else{
        cout << 2 << endl;
        return;
    }
}

int main(){
  ll t; cin >> t;
  while(t--){
    solve();
  }
}