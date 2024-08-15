#include<bits/stdc++.h>
using namespace std;
#define ll long long

void rec(vector<ll>& v, int n, int k) {
    if (k <= 0) {
        return;
    }
    if (k <= n) {
        v[k] = 200;
        if (k + 1 <= n) {
            v[k + 1] = -201;
        }
    } else {
        v[n] = 1000;
        rec(v, n - 1, k - n);
    }
}

void solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> v(n + 1, -1);
    rec(v, n, k);
    for (int i = 1; i <= n; i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main() {
    ll t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}
