#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool bfs(int n, const vector<vector<int>> &adj, vector<int> &pair_u, vector<int> &pair_v, vector<int> &dist) {
    queue<int> q;
    // Initialize distances
    for(int u=1; u<=n; u++) {
        if(pair_u[u] == 0) {
            dist[u] = 0;
            q.push(u);
        }
        else {
            dist[u] = INT32_MAX;
        }
    }
    dist[0] = INT32_MAX;
    
    while(!q.empty()) {
        int u = q.front(); q.pop();
        if(u != 0) {
            for(auto &v: adj[u]) {
                if(dist[pair_v[v]] == INT32_MAX) {
                    dist[pair_v[v]] = dist[u]+1;
                    q.push(pair_v[v]);
                }
            }
        }
    }
    return dist[0] != INT32_MAX;
}

bool dfs(int u, const vector<vector<int>> &adj, vector<int> &pair_u, vector<int> &pair_v, vector<int> &dist) {
    if(u != 0) {
        for(auto &v: adj[u]) {
            if(dist[pair_v[v]] == dist[u]+1) {
                if(dfs(pair_v[v], adj, pair_u, pair_v, dist)) {
                    pair_u[u] = v;
                    pair_v[v] = u;
                    return true;
                }
            }
        }
        dist[u] = INT32_MAX;
        return false;
    }
    return true;
}
int hopcroftKarp(int n, const vector<vector<int>> &adj) {
    // Node indices: Left side (1..n), Right side (1..n)
    vector<int> pair_u(n+1, 0); // Left to Right
    vector<int> pair_v(n+1, 0); // Right to Left
    vector<int> dist(n+1, 0);
    
    int result = 0;
    while(bfs(n, adj, pair_u, pair_v, dist)) {
        for(int u=1; u<=n; u++) {
            if(pair_u[u] == 0) {
                if(dfs(u, adj, pair_u, pair_v, dist)) {
                    result++;
                }
            }
        }
    }
    return result;
}

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> left_x(n+1, 1); 
    vector<int> right_x(n+1, n); 
    
    for(int x=1; x<=n; x++) {
        for(int t=1; t<=n; t++) {
            if(s[t-1] == 's') {
                if(x <= (n - t +1)) {
                    left_x[x] = max(left_x[x], t);
                }
            }
        }
        for(int i=x; i<=n; i++) {
            if(s[i-1] == 'p') {
                right_x[x] = min(right_x[x], i);
            }
        }
    }
    
    bool possible = true;
    for(int x=1; x<=n; x++) {
        if(left_x[x] > right_x[x]) {
            possible = false;
            break;
        }
    }
    if(!possible){
        cout << "NO\n";
        return;
    }

    vector<vector<int>> adj(n+1, vector<int>());
    for(int x=1; x<=n; x++) {
        for(int pos=left_x[x]; pos<=right_x[x]; pos++) {
            adj[x].push_back(pos);
        }
    }
    
    int match_size = hopcroftKarp(n, adj);
    
    if(match_size == n){
        cout << "YES\n";
    }
    else{
        cout << "NO\n";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}