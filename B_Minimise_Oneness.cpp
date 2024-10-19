#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n; cin >> n;
    string ans = "1";
    for(int i = 1; i < n; i++){
        ans += "0";
    }
    cout << ans << endl;
}

int main(){
  ll t; cin >> t;
  while(t--){
    solve();
  }
}