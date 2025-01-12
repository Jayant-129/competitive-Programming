#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n , x , y; cin >> n >> x >> y;
    ll m = max(x,y);
    ll z = min(x,y);
    ll val = (m - z - 1);
    if(val % 2 == 1){
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