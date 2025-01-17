#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n; cin >> n;
    ll k = 2 , mid = (n + 1)/2;
    for(int i = 1; i <= n; i++){
        if(i == 1 || i == mid || i == n){
            cout << 1 << " ";
        }
        else{
            cout << k << " ";
            k++;
        }
    }
    cout << endl;
}

int main(){
  ll t; cin >> t;
  while(t--){
    solve();
  }
}