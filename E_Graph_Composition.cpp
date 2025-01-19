#include <bits/stdc++.h>
using namespace std;
#define ll long long

class DSU {
public:
    vector<int> parent, size;
    int components;

    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);
        components = n;
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unionSets(int x, int y) { 
        int root_x = find(x);
        int root_y = find(y);

        if (root_x != root_y) {
            if (size[root_x] > size[root_y]) {
                parent[root_y] = root_x;
                size[root_x] += size[root_y];
            } else {
                parent[root_x] = root_y;
                size[root_y] += size[root_x];
            }
            components--;
        }
    }

    bool connected(int x, int y) {
        return find(x) == find(y);
    }

    int countComponents() {
        return components;
    }
};

void solve() {
    ll n, m1, m2;
    cin >> n >> m1 >> m2;
    vector<pair<int, int>> edges;

    for (int i = 0; i < m1; i++) {
        ll x, y;
        cin >> x >> y; x--; y--;
        edges.push_back({x, y});
    }

    DSU ds(n);
    DSU ds2(n);

    for (int i = 0; i < m2; i++) {
        ll x, y;
        cin >> x >> y; x--; y--;
        ds.unionSets(x, y);
    }

    ll cnt = 0;
    for (auto [i, j] : edges) {
        if (!ds.connected(i, j)) { 
            cnt++;
        } else {
            ds2.unionSets(i, j); 
        }
    }

    cout << cnt + (ds2.countComponents() - ds.countComponents()) << endl;
}

int main() {
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
}
