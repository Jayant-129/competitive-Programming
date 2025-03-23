#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll x , y , a; cin >> x >> y >> a;
    ll val = x + y;
    ll left = a % val;
    left++;
    if(left <= x){
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