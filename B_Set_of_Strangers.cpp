#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cin >> grid[i][j];
        }
    }
    
    unordered_map<int, pair<bool, bool>> parity;
    unordered_set<int> colors;
    
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            int c = grid[i][j];
            colors.insert(c);
            if ((i+j)&1) 
                parity[c].second = true;
            else
                parity[c].first = true;
        }
    }
    unordered_map<int, bool> adj;
    for (int c : colors)
        adj[c] = false;
    
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            int c = grid[i][j];
            if (j+1 < m && grid[i][j+1] == c)
                adj[c] = true;
            if (i+1 < n && grid[i+1][j] == c)
                adj[c] = true;
        }
    }
    
    unordered_map<int, int> cost;
    for (int c : colors) {
        auto pr = parity[c];
        if (!pr.first || !pr.second) {
            cost[c] = 1;
        } else {
            cost[c] = (adj[c] ? 2 : 1);
        }
    }
    
    int totalCost = 0;
    for (auto &p : cost)
        totalCost += p.second;
        
    int ans = totalCost; 
    for (int T : colors) {
        ans = min(ans, totalCost - cost[T]);
    }

    cout << ans << "\n";
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}