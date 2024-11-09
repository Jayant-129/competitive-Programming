#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    ll n;
    cin >> n;
    vector<ll> v(n + 1, 0);
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    vector<bool> dp(n + 2, false); 
    dp[0] = true;

    for (ll i = 1; i <= n; i++) {
        if (dp[i - 1] && (i + v[i]) <= n) {
            dp[i + v[i]] = true;
        }
        if ((i - v[i] - 1) >= 0 && dp[i - v[i] - 1]) {
            dp[i] = true;
        }
    }

    if (dp[n]) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}