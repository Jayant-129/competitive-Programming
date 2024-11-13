#include<bits/stdc++.h>
using namespace std;
#define ll long long

vector<vector<ll>> adj;
vector<ll> v;

ll dfs(ll i, ll parent){
    ll ansg = 0;
    //   if(adj[i].size() == 2){
    //     if(adj[i][0] == parent){
    //         return v[adj[i][1]] - 1;
    //     }
    //     else{
    //         return v[adj[i][0]] - 1;
    //     }
    // }
    for(auto& j: adj[i]){
        if(j != parent){
            ll ans = v[j] - 1;
            for(auto& k: adj[i]){
                if(k != parent && k != j){
                    ans = (v[j] - 1) + dfs(k, i);
                }
            }
            ansg = max(ansg, ans);
        }
    }
    return ansg;
}

ll dfs1(ll i, ll parent){
    ll ans = 1;
    for(auto& j: adj[i]){
        if(j != parent){
            ans += (dfs1(j, i));
        }
    }
    v[i] = ans;
    return ans;
}

void solve(){
    ll n; 
    cin >> n;
    adj.clear();
    adj.resize(n + 1);
    for(int i = 1; i < n; i++){
        ll x, y; 
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    v.clear();
    v.resize(n + 1, 0);
    dfs1(1, -1);
    cout << dfs(1, -1) << endl;
}

int main(){
    ll t; 
    cin >> t;
    while(t--){
        solve();
    }
}