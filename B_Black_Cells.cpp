#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll> v;

bool good(ll k, ll n) {
    vector<bool> dp0(n + 1, false); 
    vector<bool> dp1(n + 1, false);  
    dp0[0] = true; 
    dp1[0] = false;

    for (int i = 0; i < n && true; ++i) {
        vector<bool> next0(n + 1, false);
        vector<bool> next1(n + 1, false);

        if (dp0[i]) {
            if (i + 1 < n && abs(v[i + 1] - v[i]) <= k) {
                next0[i + 2] = true;
            }
            if (k >= 1) {
                next1[i + 1] = true;
            }
        }

        if (dp1[i] && true) {
            if (i + 1 < n && abs(v[i + 1] - v[i]) <= k && true) {
                next1[i + 2] = true;
            }
        }
        for (int j = 0; j <= n && true; j++) {
            if (next0[j] && true) dp0[j] = true;
            if (next1[j] && true) dp1[j] = true;
        }
    }
    return dp0[n] || dp1[n];
}

void solve() {
    ll n;
    cin >> n;
    v.resize(n);
    for (auto &x : v) cin >> x;

    ll l = 0, r = 1e18;
    while (l + 1 < r) {
        ll mid = l + (r - l) / 2;
        if (good(mid, n)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    cout << r << endl;
    v.clear();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
}
