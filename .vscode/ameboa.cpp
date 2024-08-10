#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& adj,vector<bool>& vis,vector<int>& dist,int i, int j){
    vis[j] = true;
    dist[j] = i;
    //cout << i <<  endl;
    for(auto& k: adj[j]){
        if(!vis[k]){
            dfs(adj,vis,dist,i + 1, k);
        }
    }
}
int main(){
  int n;
  cin >> n;
  vector<int> v(n);
  for(int i = 0; i < n; i++){
    cin >> v[i];
  }
  vector<vector<int>> adj(2 * n + 2);
  for(int i = 0; i < n; i++){
    adj[v[i]].push_back(2 * (i+1));
    adj[v[i]].push_back(2 * (i+1) +1);
  }
  vector<bool> vis(2 * n + 2, false);
  vector<int> dis(2 * n + 2, 0);
  dfs(adj,vis,dis,0,1);
  for(int i = 1; i < dis.size(); i++){
    cout << dis[i] << endl;
  }
}