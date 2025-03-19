#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n , m; cin >> n >> m;
    vector<ll> v(m, 0); 
    for(int i = 0; i < m; i++){
        cin >> v[i];
        if(v[i] == n) v[i]--;
    }
    sort(v.begin(),v.end());
    vector<ll> suff(m + 1, 0);
    for(int i = m - 1; i >= 0; i--){
        suff[i] = v[i];
        suff[i] += suff[i + 1];
    }
    ll ans = 0;
    for(int i = 0; i < m; i++){
        auto it = lower_bound(v.begin() + (i + 1),v.end(), n - (v[i]));
        ll idx = distance(v.begin(), it);
        ll val = (suff[idx] - ((m - idx) * (n - v[i] - 1)));
        ans += (val * 2 );
    }
    cout << ans << endl;
}

int main(){
  ll t; cin >> t;
  while(t--){
    solve();
  }
}

// 4 4 8 8 11 13 14 14 16 17