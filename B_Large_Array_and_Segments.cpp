#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n,k,x, sum = 0; cin >> n >> k >> x;
    vector<ll> v(n); for(auto &i: v) cin >> i, sum += i;
    ll val = (x/sum); ll curr  = val * sum;

    ll idx = -1;
    for(int i = n - 1; i >= 0; i--){
        if(curr >= x){
            idx = i;
            break;
        }
        curr += v[i];
    }
    ll taken = (val * n) + (n - idx - 2);
    if(n * k < taken){
        cout << 0 << endl;
        return;
    }
    cout << (n * k) - (taken)<< endl;
}
int main(){
  ll t; cin >> t;
  while(t--){
    solve();
  }
}