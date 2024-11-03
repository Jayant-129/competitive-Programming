#include <bits/stdc++.h>
using namespace std;
#define ll long long
map<char, bool> vis;
vector<string> v;

vector<ll> find1(vector<ll>& v2, ll n) {
    if (v2.size() == 1) return {v2[0]};
    if (v2[0] == n) return {v2[1]};
    ll l = 0, r = v2.size() - 1;
    ll mid;
    while (l + 1 < r) {
        mid = l + (r - l) / 2;
        if (v2[mid] < n) {
            l = mid;
        } else {
            r = mid;
        }
    }
    vector<ll> v1;
    if (r + 1 < v2.size() && abs(v2[l] - n) > abs(v2[r + 1] - n)) {
        v1.push_back(v2[r + 1]);
    }
    v1.push_back(v2[r]);
    return v1;
}

ll fxn(map<char, vector<ll>>& mp, ll curr, ll dest) {
    ll ans = INT_MAX;
    for (auto& i : v[curr]) {
        if (!vis[i]) {
            if (find(mp[i].begin(), mp[i].end(), dest) != mp[i].end()) {
                return abs(dest - curr);
            }
            vis[i] = true;
            vector<ll> x = find1(mp[i], curr);
            for (ll k : x) {
                ans = min(ans, abs(k - curr) + fxn(mp, k, dest));
            }
            vis[i] = false;
        }
    }
    return ans;
}

void solve() {
    ll n, q;
    cin >> n >> q;
    map<char, vector<ll>> mp;
    v.resize(n + 1);
    for (ll i = 1; i <= n; i++) {
        char a, b;
        cin >> a >> b;
        v[i] = {a, b};
        mp[a].push_back(i);
        mp[b].push_back(i);
    }
    for (auto& i : mp) {
        sort(i.second.begin(), i.second.end());
    }
    for (int i = 0; i < q; i++) {
        ll a, b;
        cin >> a >> b;
        vis.clear();  // clear the visited map for each query
        ll ans = fxn(mp, a, b);
        if (ans == INT_MAX) {
            cout << -1 << endl;
        } else {
            cout << ans << endl;
        }
    }
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
