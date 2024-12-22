#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n,k; cin >> n >> k;
    vector<ll> a(n,0);
    vector<ll> b(n,0);
    vector<ll> v;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        v.push_back(a[i]);
    }
    for(int i = 0; i < n; i++){
        cin >> b[i];
        v.push_back(b[i]);
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    sort(v.begin(),v.end());
    ll ans = 0;
    for(int i = 0; i < v.size(); i++){
        auto it = lower_bound(a.begin(),a.end(),v[i]);
        auto it2 = lower_bound(b.begin(),b.end(),v[i]);
        ll idx = it - a.begin();
        ll idx2 = it2 - b.begin();
        if((idx - idx2) <= k){
            ans = max(ans,(n - idx2)*v[i]);
        }
    }
    cout << ans << endl;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  ll t; cin >> t;
  while(t--){
    solve();
  }
}