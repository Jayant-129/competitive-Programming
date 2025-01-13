#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
void solve() {
    int l, r;
    cin >> l >> r;
    int k = 31 - __builtin_clz(l ^ r);
    int a = l | ((1 << k) - 1), b = a + 1, c = (a == l ? r : l);
    cout << a << " " << b << " " << c << "\n";
}
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}
