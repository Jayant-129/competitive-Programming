#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for(auto &x : a) cin >> x;
    for(int i=0;i<n;i++){
        bool valid = true;
        for(int j=0;j<n;j++) {
            if(i == j) continue;
            if(abs(a[i] - a[j]) % k == 0){
                valid = false;
                break;
            }
        }
        if(valid){
            cout << "YES\n" << (i+1) << "\n";
            return;
        }
    }
    cout << "NO\n";
}

int main(){
  ll t; cin >> t;
  while(t--){
    solve();
  }
}