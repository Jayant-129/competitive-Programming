#include<bits/stdc++.h>
using namespace std;
#define ll long long

bool isPrime(ll n){
    if(n < 2) return false;
    for(int i = 2; i * i <= n; i++){
        if(n % i == 0){
            return false;
        }
    }
    return true;
}

void solve(){
    ll n , k; cin >> n >> k;
    if(n == 1 && (k == 2)){
        cout << "YES" << endl;
        return;
    }
    if(k > 1){
        cout << "NO" << endl;
    }
    else{
        if(isPrime(n)){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
}

int main(){
  ll t; cin >> t;
  while(t--){
    solve();
  }
}