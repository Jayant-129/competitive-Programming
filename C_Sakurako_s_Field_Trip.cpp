#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n; cin >> n;
    vector<ll> v(n , 0); for(auto& i: v) cin >> i;
    int i = 1 , j = n - 2;
    while(i <= j){
      if(v[i] == v[i - 1] || v[j] == v[j + 1]){
        swap(v[i], v[j]);
      }
      i++;
      j--;
    }
    ll cnt = 0;
    for(int k = 0; k < (n - 1); k++){
      if(v[k] == v[k + 1]){
        cnt++;
      }
    }
    cout << cnt << endl;
}

int main(){
  ll t; cin >> t;
  while(t--){
    solve();
  }
}