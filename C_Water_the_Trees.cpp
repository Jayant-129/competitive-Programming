#include <bits/stdc++.h>
using namespace std;
#define ll long long


void solve(){
    ll n;
        cin >> n;
        vector<ll> h(n);
        for (auto &x : h) {
           cin >> x;
        }
        
        ll mx = *max_element(h.begin(), h.end());
        ll ans = 1e18;
        for (auto need : {mx}) {
            ll l = 0, r = 1e18;
            ll res = -1;
            while (l <= r) {
                ll mid = (l + r) >> 1;
                ll cnt1 = (mid + 1) / 2, cnt2 = mid - cnt1;
                ll need1 = 0;
                for (auto ch : h) {
                    ll cur = (need - ch) / 2;
                    if ((need - ch) % 2 == 1) {
                        ++need1;
                    }
                    if (cnt2 >= cur) {
                        cnt2 -= cur;
                    } else {
                        cur -= cnt2;
                        cnt2 = 0;
                        need1 += cur * 2;
                    }
                }
                if (need1 <= cnt1) {
                    res = mid;
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
            ans = min(ans, res);
        }
        
        cout << ans << endl;
}

int main() {
    
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
        
    return 0;
}