#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAXN 2000005

ll factorial[MAXN];
ll inv_factorial[MAXN];

ll mod_pow(ll a, ll b, ll m) {
    ll res = 1;
    while (b > 0) {
        if (b % 2 == 1) {
            res = (res * a) % m;
        }
        a = (a * a) % m;
        b /= 2;
    }
    return res;
}

void precompute_factorials() {
    factorial[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        factorial[i] = factorial[i - 1] * i % MOD;
    }
    inv_factorial[MAXN - 1] = mod_pow(factorial[MAXN - 1], MOD - 2, MOD);
    for (int i = MAXN - 2; i >= 0; i--) {
        inv_factorial[i] = inv_factorial[i + 1] * (i + 1) % MOD;
    }
}

ll nCr(ll n, ll r) {
    if (r > n || r < 0) return 0;
    return factorial[n] * inv_factorial[r] % MOD * inv_factorial[n - r] % MOD;
}

void solve() {
    ll k, n;
    cin >> n >> k;
    vector<ll> v(n, 0);
    ll cnt1 = 0, cnt0 = 0;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v[i] = x;
        if (x == 0) {
            cnt0++;
        } 
        else {
            cnt1++;
        }
    }
    ll sum = 0;
    ll mid = (k + 1) / 2;
    for (int i = mid; i <= k; i++) {
        ll val = k - i;
        if (val > cnt0) {
            continue;
        } else {
            ll num1 = nCr(cnt0, val);
            ll num2 = nCr(cnt1, i);
            sum = (sum + (num1 * num2) % MOD) % MOD;
        }
    }

    cout << sum << endl;
}

int main() {
    ios::sync_with_stdio(0);cin.tie(0);
    precompute_factorials();
    ll t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }

    return 0;
}
