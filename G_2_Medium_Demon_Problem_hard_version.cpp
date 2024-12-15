#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        vector<ll> r(n);
        for(auto &x : r){
            cin >> x;
            x--; // Convert to 0-based indexing
        }
        
        // Step 1: Calculate in-degrees
        vector<int> in_degree(n, 0);
        for(int i=0;i<n;i++){
            in_degree[r[i]]++;
        }
        
        // Step 2: Kahn's algorithm to remove nodes not in cycles
        queue<int> q;
        // Enqueue all nodes with in-degree 0
        for(int i=0;i<n;i++){
            if(in_degree[i]==0){
                q.push(i);
            }
        }
        
        // Remove nodes with in-degree 0 iteratively
        while(!q.empty()){
            int u = q.front(); q.pop();
            int v = r[u];
            in_degree[v]--;
            if(in_degree[v]==0){
                q.push(v);
            }
        }
        
        // Step 3: Identify nodes in cycles
        vector<bool> in_cycle(n, false);
        for(int i=0;i<n;i++){
            if(in_degree[i] >0){
                in_cycle[i] = true;
            }
        }
        
        // Step 4: Build reverse adjacency list
        vector<vector<int>> rev_adj(n, vector<int>());
        for(int i=0;i<n;i++){
            rev_adj[r[i]].push_back(i);
        }
        
        // Step 5: BFS from cycle nodes to find distances
        // Initialize distances to -1
        vector<int> distance_to_cycle(n, -1);
        queue<int> bfs_q;
        // Enqueue all cycle nodes with distance 0
        for(int i=0;i<n;i++){
            if(in_cycle[i]){
                distance_to_cycle[i] = 0;
                bfs_q.push(i);
            }
        }
        
        while(!bfs_q.empty()){
            int u = bfs_q.front(); bfs_q.pop();
            for(auto &v : rev_adj[u]){
                if(distance_to_cycle[v]==-1){
                    distance_to_cycle[v] = distance_to_cycle[u] +1;
                    bfs_q.push(v);
                }
            }
        }
        
        // Step 6: Find the maximum distance
        int max_distance = 0;
        for(int i=0;i<n;i++){
            if(distance_to_cycle[i] > max_distance){
                max_distance = distance_to_cycle[i];
            }
        }
        
        // Step 7: Stabilization year is max_distance +2
        // This aligns with the simulation where stabilization occurs after all plushies have reached cycles
        ll stabilization_year = (ll)max_distance + 2;
        cout << stabilization_year << "\n";
    }
    
    return 0;
}