#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll dp[16][3];

ll dpans(string R, ll n, ll tight, ll &total) {
    if (n == 0) {
        return 1;
    }
    if (dp[n][tight] != -1) {
        return dp[n][tight];
    }
    ll up = tight ? (R[R.size() - n] - '0') : 9;
    ll answer = 0;
    for (ll i = 0; i <= up; i++) {
        ll ans = dpans(R, n - 1, tight && (i == up), total);
        answer += ans;
        total += (i * ans);
    }
    return dp[n][tight] = answer;
}

void solve() {
    ll a, b;
    cin >> a >> b;
    string R = to_string(b);
    string L = to_string(a - 1);

    ll total1 = 0;
    memset(dp, -1, sizeof(dp));
    dpans(R, R.size(), 1, total1);

    ll total2 = 0;
    memset(dp, -1, sizeof(dp));
    dpans(L, L.size(), 1, total2);

    cout << total1 - total2 << endl;
}

int main() {
    ll t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}
