#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n , k; cin >> n >> k;
    string s; cin >> s;
    ll score = 0;
    vector<ll> v(n);
    for(ll i = 0; i < n; i++){
        if(s[i] == '0'){
            score -= i;
        }
        else{
            score += i;
        }
        v[i] = score;
    }
    vector<ll> suf(n);
    for(ll i = n - 1; i >= 0; i--){
        if(s[i] == '0'){
            suf[i] = -1;
        }
        else{
            suf[i] = 1;
        }
        if(i < (n - 1)) suf[i] += suf[i + 1];
        if(suf[i] >= k){
            cout << 2 << endl;
            return;
        }
    }
    ll maxi = INT_MIN; ll idx = n + 1;
    for(ll i = 0; i < n; i++){
        ll x = 0;
        if(i) x = v[i - 1];
        if(suf[i] > 0){
            maxi = max(x + (suf[i]) * i, maxi);
            if(maxi >= k){
                idx = min(idx,i + 1);
            }
        }
    }
    if(idx < n + 1){
        cout << idx << endl;
        return;
    }
    cout << -1 << endl;
}
int main(){
  ll t; cin >> t;
  while(t--){
    solve();
  }
}