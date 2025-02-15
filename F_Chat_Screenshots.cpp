#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

bool hasCycle(int n, const vector<vector<int>>& adj) {
    // We'll use Kahn's algorithm for cycle detection.
    // If we can't topologically sort all nodes, there's a cycle.
    vector<int> inDegree(n + 1, 0);
    for(int u = 1; u <= n; u++){
        for (int v: adj[u]){
            inDegree[v]++;
        }
    }
    // All nodes with zero in-degree in a queue
    queue<int> q;
    for(int u = 1; u <= n; u++){
        if(inDegree[u] == 0) {
            q.push(u);
        }
    }
    int visitedCount = 0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        visitedCount++;
        // Decrease in-degree of neighbors
        for(int v : adj[u]){
            if(--inDegree[v] == 0){
                q.push(v);
            }
        }
    }
    // If we visited all nodes, there's no cycle
    // Otherwise, there's a cycle in the graph
    return (visitedCount < n);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        
        // We'll build a directed graph of size n (1-based).
        // Each consecutive pair in a screenshot's "other participants" imposes an edge.
        // We ignore the first element (the user who posted the screenshot).
        // Then for each consecutive pair [arr[i], arr[i+1]], we add an edge: arr[i] -> arr[i+1].
        vector<vector<int>> adj(n + 1);

        // We also read each screenshot's array
        for(int i = 0; i < k; i++){
            vector<int> shot(n);
            for(int j = 0; j < n; j++){
                cin >> shot[j];
            }
            // Build edges from consecutive pairs, skipping index 0 (the user themselves)
            // We only add edges among the subsequent participants.
            // Ex: shot = [ x, p1, p2, ... p_{n-1} ]
            // edges: p1->p2, p2->p3, ... p_{n-2}->p_{n-1}
            // (1-based nodes are guaranteed by the problem)
            for(int j = 1; j < n - 1; j++){
                int from = shot[j];
                int to = shot[j + 1];
                adj[from].push_back(to);
            }
        }

        // Now we check for cycle in this directed graph of n nodes
        bool cycle = hasCycle(n, adj);

        // If there's a cycle, answer is NO, else YES
        cout << (cycle ? "NO\n" : "YES\n");
    }
    return 0;
}