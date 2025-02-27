#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n; cin >> n;
    if(n == 0 || n == 1 || n == 2){
        cout << n + 1 << endl;
        return;
    }
    else{
        ll val = n % 15;
        //cout << val << endl;
        if(val == 0){
            cout << ((n - 1)/15) * 3 + 4 << endl;
        }
        else if(val == 1){
            cout << ((n - 2)/15) * 3 + 5 << endl;
        }
        else{
            cout << ((n)/15) * 3 + 3 << endl;
        }
    }
}

int main(){
  ll t; cin >> t;
  while(t--){
    solve();
  }
}