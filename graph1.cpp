#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll n, m;
    cin >> n >> m;

    vector<vector<pair<ll, ll>>> adj(n + 1);

    for (ll i = 0; i < m; i++) {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back({v, 1});
        adj[v].push_back({u, 0});
    }
    ll s, s1;
    cin >> s >> s1;
    vector<ll> d(n + 1, INT_MAX);
    priority_queue<pair<ll, pair<ll, ll>>, vector<pair<ll, pair<ll, ll>>>, greater<pair<ll, pair<ll, ll>>>> pq;
    d[s] = 0;
    pq.push({0,{s,0}});
    pq.push({0,{s,1}});
    while (!pq.empty()) {
        auto curr = pq.top();
        pq.pop();
        
        ll currDist = curr.first;
        ll currNode = curr.second.first;
        ll currWeightType = curr.second.second;

        if (currDist > d[currNode]) {
            continue;
        }
        for (auto& edge : adj[currNode]) {
            ll neighbor = edge.first;
            ll edgeWeight = edge.second;
            if (!(edgeWeight ^ currWeightType)) {
                if (d[neighbor] > currDist) {
                    d[neighbor] = currDist;
                    pq.push({currDist, {neighbor, edgeWeight}});
                }
            } else {
                if (d[neighbor] > currDist + 1) {
                    d[neighbor] = currDist + 1;
                    pq.push({currDist + 1, {neighbor, edgeWeight}});
                }
            }
        }
    }
    cout << d[s1] << endl;
}
