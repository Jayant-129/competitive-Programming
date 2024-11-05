#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll M = 1e9 + 7;
long long fxn(long long base, long long exp, long long mod) {
    long long result = 1;
    base = base % mod; 
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        exp = exp >> 1;
        base = (base * base) % mod;  
    }
    return result;
}
void solve(){
    ll l , r , k; cin >> l >> r >> k;
    int cnt = 0, i = 1;
    while(k * i < 10){
        cnt++;
        i++;
    }
    if(l == 0){
        cout << ((fxn(cnt + 1,r,M)) % M) - 1 << endl;
    }
    else{
        cout << (((fxn(cnt + 1,r,M)) % M) - ((fxn(cnt + 1,l,M)) % M) + M) % M << endl;
    }
}
int main(){
  ll t; cin >> t;
  while(t--){
    solve();
  }
}