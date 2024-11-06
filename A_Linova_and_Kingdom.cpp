#include <bits/stdc++.h>
using namespace std;
#define maxn 200005
#define ll long long

vector<vector<ll>> adj(maxn);     
ll depth_arr[maxn] = {0};       
ll size_arr[maxn] = {0};            
ll det_arr[maxn];                    

long long ans = 0;
bool cmp(ll a, ll b) { return a > b; }

ll dfs(ll u, ll f) {
    depth_arr[u] = depth_arr[f] + 1;
    size_arr[u] = 1;
    for(auto &neighbor : adj[u]) {
        if(neighbor == f) continue;  
        size_arr[u] += dfs(neighbor, u);
    }
    det_arr[u] = size_arr[u] - depth_arr[u];
    return size_arr[u];
}

void solve(){
    ll n, k;
    cin >> n >> k;

    for(int i = 1; i < n; ++i){
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i =1;i<=n;i++){
        depth_arr[i] = 0;
        size_arr[i] = 0;
        det_arr[i] = 0;
        
    }

    dfs(1, 0); 
    vector<ll> det_vector;
    for(int i =1;i<=n;i++) det_vector.push_back(det_arr[i]);

    nth_element(det_vector.begin(), det_vector.begin() + (n - k), det_vector.end(), cmp);
    ans = 0;
    for(int i =0;i < n - k;i++) ans += det_vector[i];

    cout << ans << "\n";
    for(int i =1;i<=n;i++) adj[i].clear();
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}