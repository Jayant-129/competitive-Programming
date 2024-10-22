#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll ans(ll n ,ll k){
    if(k <= ceil(n/2.0)){
        return (2 * k - 1);
    }
    return 2 * ans(floor(n/2.0),k - ceil(n/2.0));
}
int main(){
  ll t; cin >> t;
  while(t--){
    ll n , k; cin >> n >> k;
    cout << ans(n,k) << endl;
  }
}