#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n; cin >> n;
    vector<ll> v(n,0);
    for(auto& x: v) cin >> x;
    ll odd = 0, even = 0, maxi = LLONG_MIN, sum = 0;
    for(int i = 0; i < n; i++){
        if(v[i] % 2){
            odd++;
        }
        else{
            even++;
        }
        maxi = max(maxi,v[i]);
        sum += v[i];
    }

    if(!even || !odd){
        cout << maxi << endl;
        return;
    }
    cout << sum - (odd - 1) << endl;
}

int main(){
  ll t; cin >> t;
  while(t--){
    solve();
  }
}