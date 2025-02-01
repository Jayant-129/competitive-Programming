#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int NMAX = 4e5 + 5;

int n;
vector<int> w;            // 1-indexed weights
vector<vector<int>> adj;  // undirected tree
vector<vector<int>> children;
vector<int> parent;

// DP state: dp[node][last_value] = -1 (not computed), 0 (losing), 1 (winning)
vector<vector<int>> dp;

// Build tree (rooted at 1)
void dfs_build(int u, int p) {
    parent[u] = p;
    for (int v : adj[u]) {
        if (v != p) {
            children[u].push_back(v);
            dfs_build(v, u);
        }
    }
}

// Dummy function: Returns true if the position (node, last_value)
// is winning for the current player.
// Replace this placeholder with your full game–theoretic analysis.
bool can_win(int node, int last_value) {
    // Base: if no valid move available, current player wins (game rule)
    if (node == 0) return true;
    
    // If already computed, return stored value.
    if (dp[node][last_value] != -1)
        return dp[node][last_value];
    
    // Initialize state to losing.
    dp[node][last_value] = 0;
    
    for (int child : children[node]) {
        if (w[child] > last_value) {
            // Dummy transition: if there is any move making opponent lose, we win.
            if (!can_win(parent[child], w[child])) {
                dp[node][last_value] = 1;
                break;
            }
        }
    }
    return dp[node][last_value];
}

// Dummy function: Returns a sorted list of first–move nodes that are winning
// for Cirno. Replace the dummy logic below with your full solution.
vector<int> compute_winning_moves() {
    vector<int> winning;
    // For each node i, simulate choosing it as the first move.
    for (int i = 1; i <= n; i++) {
        // Reset DP state for each simulation.
        dp.assign(n + 1, vector<int>(n + 5, -1));  // n+5 covers possible last_value values
        
        // In the first move, threshold becomes w[i] and the remaining tree is the original tree
        // minus the subtree of i. We simulate the outcome from state (parent[i], w[i]).
        if (!can_win(parent[i], w[i])) {
            winning.push_back(i);
        }
    }
    sort(winning.begin(), winning.end());
    return winning;
}

void solve() {
    cin >> n;
    
    // Initialize arrays.
    w.assign(n + 1, 0);
    adj.assign(n + 1, vector<int>());
    children.assign(n + 1, vector<int>());
    parent.assign(n + 1, 0);
    
    for (int i = 1; i <= n; i++) {
        cin >> w[i];
    }
    
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    // Build the tree rooted at node 1.
    dfs_build(1, 0);
    
    // Compute winning moves for Cirno.
    vector<int> winning = compute_winning_moves();
    if (winning.empty()) {
        cout << "0" << "\n";
    } else {
        cout << winning.size();
        for (int node : winning)
            cout << " " << node;
        cout << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}