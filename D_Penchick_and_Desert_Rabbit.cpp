#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long

class DSU {
    vector<ll> parent, rank;
public:
    DSU(ll n) {
        parent.resize(n);
        rank.resize(n, 1);
        for (ll i = 0; i < n; ++i) parent[i] = i;
    }

    ll find(ll x) {
        if (parent[x] != x) 
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(ll x, ll y) {
        ll rootX = find(x);
        ll rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
};

vector<vector<ll>> findSmallerAndLarger(const vector<ll>& arr, bool findSmaller) {
    ll n = arr.size();
    vector<pair<ll, ll>> indexedArr;
    
    for (ll i = 0; i < n; ++i) 
        indexedArr.emplace_back(arr[i], i);

    if (findSmaller) {
        sort(indexedArr.begin(), indexedArr.end(), [](pair<ll, ll>& a, pair<ll, ll>& b) {
            return a.first == b.first ? a.second < b.second : a.first < b.first;
        });
    } else {
        sort(indexedArr.begin(), indexedArr.end(), [](pair<ll, ll>& a, pair<ll, ll>& b) {
            return a.first == b.first ? a.second > b.second : a.first > b.first;
        });
    }
    
    vector<vector<ll>> result(n);
    for (const auto& [val, idx] : indexedArr) {
        for (ll i = 0; i < n; ++i) {
            if ((findSmaller && arr[i] < val && i > idx) || (!findSmaller && arr[i] > val && i < idx)) {
                result[idx].push_back(i);
            }
        }
    }
    return result;
}

ll dfs(vector<ll>& dp, vector<vector<ll>>& s, vector<vector<ll>>& l, vector<bool>& vis, const vector<ll>& v, ll i, ll maxi) {
    vis[i] = true;
    if (dp[i] != -1) return dp[i];
    ll ans = max(v[i], maxi);
    for (auto& j : s[i]) {
        if (!vis[j]) {
            dfs(dp, s, l, vis, v, j, ans);
        }
    }
    for (auto& j : l[i]) {
        if (!vis[j]) {
            dfs(dp, s, l, vis, v, j, ans);
        }
    }
    return dp[i] = ans;
}

void solve() {
    ll n;
    cin >> n;
    vector<ll> v(n); 
    for (auto& x : v) cin >> x;
    vector<pair<ll, ll>> v1;
    for (ll i = 0; i < n; i++) {
        v1.push_back({v[i], i});
    }
    vector<ll> dp(n, -1);
    vector<vector<ll>> s = findSmallerAndLarger(v, true);
    vector<vector<ll>> l = findSmallerAndLarger(v, false);
    vector<bool> vis(n, false);
    sort(v1.begin(), v1.end(), greater<pair<ll, ll>>());
    for (auto& i : v1) {
        if(!vis[i.second]) dfs(dp, s, l, vis, v, i.second, i.first);
    }
    for (ll i = 0; i < n; i++) {
        cout << dp[i] << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
