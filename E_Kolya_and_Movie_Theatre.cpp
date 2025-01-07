#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n, m, d;
        cin >> n >> m >> d;
        vector<ll> a(n);
        for (ll i = 0; i < n; ++i) {
            cin >> a[i];
        }
        ll ans = 0;
        set<pair<ll, ll>> s;
        ll sum = 0;
        for (ll i = 0; i < n; ++i) {
            ll cur = sum + a[i] - d * (i + 1);
            ans = max(ans, cur);
            if (a[i] > 0) {
                s.insert({a[i], i});
                sum += a[i];
                if (s.size() >= m) {
                    sum -= (s.begin()->first);
                    s.erase(s.begin());
                }
            }
        }
        cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll t; 
    cin >> t;
    while(t--){
        solve();
    }
}