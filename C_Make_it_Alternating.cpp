#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
void solve(){
    string s;
    cin >> s;
    ll mul = 1 , n  = s.size();
    ll k = 0;
    for(ll i = 0 ;i < n;i++){
        ll len = 1;
        if(i < (n -1) && s[i] == s[i + 1]){
            ll j = i;
            while(j < (n-1) && s[j] == s[j + 1]){
                j++;
            }
            len = j - i + 1;
            i = j;
        }
        mul = (mul * (len % MOD))% MOD;
        k++;
    }
    ll fac = 1;
    for(ll i = 1; i <= (n - k); i++){
        fac = (fac * (i % MOD))% MOD;
    }
    //cout << fac << " " << mul <<  endl;
    cout << n - k << " " <<  (fac * mul)%MOD << endl;
}

int main(){
  ll t;
  cin >> t;
  while(t-- > 0){
    solve();
  }
}