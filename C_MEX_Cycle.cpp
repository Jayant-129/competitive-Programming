#include<bits/stdc++.h>
using namespace std;
#define ll long long

vector<ll> ans;
vector<vector<int>> adj;

void fxn(int i) {
    ll ava = 0;
    vector<ll> v;
    for (auto& j : adj[i]) {
        v.push_back(ans[j]);
    }
    sort(v.begin(), v.end());
    for (auto& j : v) {
        if (j == ava) {
            ava++;
        }
    }
    ans[i] = ava;
}

void solve() {
    ll n, x, y;
    cin >> n >> x >> y;
    x -= 1;
    y -= 1;
    
    adj.assign(n, vector<int>());
    ans.assign(n, INT_MAX);

    for (int i = 0; i < n; i++) {
        adj[i].push_back((i - 1 + n) % n);
        adj[i].push_back((i + 1) % n);
    }
    if(find(adj[x].begin(), adj[x].end(), y) == adj[x].end()){
        adj[x].push_back(y);
    }
    if(find(adj[y].begin(), adj[y].end(), x) == adj[y].end()){
        adj[y].push_back(x);
    }
    for (int i = 0; i < n; i++) {
        fxn(i);
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}

int main() {
    ll t; 
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
