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
            x--;
        }
        
        vector<int> in_degree(n, 0);
        for(int i=0;i<n;i++){
            in_degree[r[i]]++;
        }
        
        queue<int> q;
        for(int i=0;i<n;i++){
            if(in_degree[i]==0){
                q.push(i);
            }
        }
        
        while(!q.empty()){
            int u = q.front(); q.pop();
            int v = r[u];
            in_degree[v]--;
            if(in_degree[v]==0){
                q.push(v);
            }
        }
        
        vector<bool> in_cycle(n, false);
        for(int i=0;i<n;i++){
            if(in_degree[i] >0){
                in_cycle[i] = true;
            }
        }
        
        vector<vector<int>> rev_adj(n, vector<int>());
        for(int i=0;i<n;i++){
            rev_adj[r[i]].push_back(i);
        }
        
        vector<int> distance_to_cycle(n, -1);
        queue<int> bfs_q;
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
        
        int max_distance = 0;
        for(int i=0;i<n;i++){
            if(distance_to_cycle[i] > max_distance){
                max_distance = distance_to_cycle[i];
            }
        }
        
        ll stabilization_year = (ll)max_distance + 2;
        cout << stabilization_year << "\n";
    }
    
    return 0;
}
