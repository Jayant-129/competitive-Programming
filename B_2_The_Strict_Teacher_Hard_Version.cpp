#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    ll n, m, q;
    cin >> n >> m >> q;
    vector<ll> pos(m);
    for (ll i = 0; i < m; i++) cin >> pos[i];
    sort(pos.begin(), pos.end());

    for (ll i = 0; i < q; i++) {
        ll x;
        cin >> x;
        auto it = upper_bound(pos.begin(), pos.end(), x);
        ll dist = 0;

        if (it == pos.begin()) {
            dist = pos[0] - 1;
        } 
        else if (it == pos.end()) {
            // If x is greater than the largest element in pos
            dist = n - pos[m - 1];
        } 
        else {
            // If x lies between two elements in pos
            ll idx_right = *it;
            ll idx_left = *(it - 1);
            dist = abs(idx_left - idx_right)/2;
        }

        cout << dist << endl;
    }
}

int main() {
    ll t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}
