#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n, k; cin >> n >> k;
    if(k % 2){
        for(int i = 1; i < n; i++){
            cout << n << " " ;
        }
        cout << n - 1 << endl;
    }
    else{
        for(int i = 2; i < n; i++){
            cout << n - 1 << " " ;
        }
        cout << n << " " << n - 1 << endl;
    }
}
int main(){
  ll t; cin >> t;
  while(t--){
    solve();
  }
}