#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n , prev = -1; cin >> n;
    vector<ll> a(n,0); map<ll,ll> mp;
    for(ll i = 0; i < n; i++) cin >> a[i];
    for(ll i = 0; i < n; i++){
        ll x; cin >> x;
        if(x > prev){
            mp[x] = i;
            prev =  x;
        }
    }

    ll mini = INT_MAX;
    for(ll i = 0; i < n; i++){
        auto it = mp.upper_bound(a[i]);
        mini = min(mini,i + it->second);
    }
    cout << mini << endl;
}

int main(){
  ll t;
  cin >> t;
  while(t-- > 0){
    solve();
  }
}