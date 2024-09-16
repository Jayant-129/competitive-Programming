#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007

ll binExpMod(ll base, ll exp, ll mod) {
    ll result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    return result;
}

void solve() {
    ll n, e = 0;
    cin >> n;
    if (n == 1) {
        cout << 0 << endl;
        return;
    }

    vector<ll> v(n, 0), suf(n, 0);
    for (int i = 0; i < n; i++) cin >> v[i];
    for (int i = n - 1; i >= 0; i--) {
        suf[i] = v[i];
        if (i < n - 1) {
            suf[i] += suf[i + 1];
            e = (e + (v[i] % M) * (suf[i + 1] % M) % M) % M;
        }
    }
    ll q = binExpMod((n * (n - 1) / 2), M - 2, M);
    
    cout << (e % M )* (q % M) % M << endl;
}

int main() {
    ll t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}
