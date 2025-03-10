#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n ,x; cin >> n >> x;
    ll sum = 0;
    for(int i = 0; i < n; i++){
        ll y; cin >> y;
        sum += y;
    }
    if(sum % n == 0 && (sum/n) == x){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
}

int main(){
  ll t; cin >> t;
  while(t--){
    solve();
  }
}