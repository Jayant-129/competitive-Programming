#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<vector<ll>> adj;
vector<bool> vis;
vector<bool> v;
ll n, x, y;
bool dfs(int i){
    vis[i] = true;
    if(i == y){
        vis[i] = false;
        return v[i] = true;
    }
    for(auto& k: adj[i]){
        if(!vis[k] && dfs(k)){
            vis[i] = false;
            return v[i] = true;
        }
    }
    vis[i] = false;
    return v[i];
}
ll cal(int i){
    vis[i] = true;
    ll ans = 1;
    for(auto& k: adj[i]){
        if(!vis[k] && !v[k]){
            ans += (cal(k));
        }
    }
    return ans;
}

void solve(){
    cin >> n >> x >> y;
    adj.resize(n + 1);
    vis.resize(n + 1,false);
    v.resize(n + 1,false);
    for(int i = 1; i < n; i++){
        ll a , b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(x);
    // for(auto i: vis){
    //     i = false;
    // }
    ll ans1 = cal(x);
    ll ans2 = cal(y);
    //cout << ans1 << " " << ans2 << " " << v[2] <<  endl;
    cout << (n * (n - 1)) - (ans1 * ans2) << endl;
    adj.clear();
    v.clear();
    vis.clear();
}

int main(){
   ios::sync_with_stdio(0); cin.tie(0);
   solve();
}