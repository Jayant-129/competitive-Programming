#include <bits/stdc++.h>
using namespace std;
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t; 
    cin >> t;
    while(t--){
        while(cin.peek() == '\n'){  
            cin.ignore();
        }
        int n, k;
        cin >> n >> k;
        vector<vector<int>> adj(n+1);
        vector<int> deg(n+1, 0);
        for (int i = 1; i < n; i++){
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
            deg[u]++;
            deg[v]++;
        }
 
        vector<bool> removed(n+1, false);
 
        multiset<pair<int,int>> ms;
        for (int i = 1; i <= n; i++){
            ms.insert({deg[i], i});
        }
 
        while(k--){
            vector<int> leaves;
            auto it = ms.begin();
            while(it != ms.end() && it->first <= 1){
                leaves.push_back(it->second);
                ++it;
            }
 
            if(leaves.empty()){
                break;
            }

            for(auto v : leaves){
                auto found = ms.find({deg[v], v});
                if(found != ms.end())
                    ms.erase(found);
                removed[v] = true;
                for(auto nb : adj[v]){
                    if(removed[nb]) continue;
                    auto f = ms.find({deg[nb], nb});
                    if(f != ms.end()){
                        ms.erase(f);
                    }
                    deg[nb]--;
                    ms.insert({deg[nb], nb});
                }
            }
        }
 
        int remaining = 0;
        for (int i = 1; i <= n; i++){
            if(!removed[i])
                remaining++;
        }
 
        cout << remaining << "\n";
    }
    return 0;
}