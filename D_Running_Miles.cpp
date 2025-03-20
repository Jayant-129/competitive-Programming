#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> b(n);
    for (auto &i : b) cin >> i;
    vector<int> pref(n), suff(n);
    for (int i = 0; i < n; ++i) {
        pref[i] = b[i] + i;
        suff[i] = b[i] - i;
    }
    for (int i = 1; i < n; ++i) {
        pref[i] = max(pref[i], pref[i - 1]);
    }
    for (int i = n - 2; i >= 0; --i) {
        suff[i] = max(suff[i], suff[i + 1]);
    }
    int ans = 0;
    for (int m = 1; m < n - 1; ++m) {
        ans = max(ans, b[m] + pref[m - 1] + suff[m + 1]);
    }
    cout << ans << endl;
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}