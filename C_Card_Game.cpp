#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<pair<ll, pair<ll, ll>>> dp;
const ll MOD = 998244353;
ll factorial(ll n)
{
    ll res = 1;
    for (ll i = 2; i <= n; i++)
    {
        res = (res * i) % MOD;
    }
    return res;
}

ll power(ll a, ll b, ll mod)
{
    ll res = 1;
    a = a % mod;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

ll modInverse(ll n, ll mod)
{
    return power(n, mod - 2, mod);
}

ll nCrModP(ll n, ll r, ll mod)
{
    if (r > n)
        return 0;
    ll fac_n = factorial(n);
    ll fac_r = factorial(r);
    ll fac_nr = factorial(n - r);
    ll inv_fac_r = modInverse(fac_r, mod);
    ll inv_fac_nr = modInverse(fac_nr, mod);
    return (fac_n * inv_fac_r % mod) * inv_fac_nr % mod;
}

void solve()
{
    ll n;
    cin >> n;
    cout << dp[n].first << " " << dp[n].second.first << " " << dp[n].second.second << endl;
}

int main()
{
    dp.resize(61);
    dp[2].first = 1, dp[2].second.first = 0, dp[2].second.second = 1;
    for (int i = 4; i <= 60; i += 2)
    {
        ll val = nCrModP(i - 1, i / 2 - 1, MOD);
        ll val2 = nCrModP(i - 2, i / 2, MOD);
        dp[i].first = (val + dp[i - 2].second.first) % MOD;
        dp[i].second.first = (val2 + dp[i - 2].first) % MOD;
        dp[i].second.second = 1;
    }
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}