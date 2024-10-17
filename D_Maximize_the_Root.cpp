#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll> v;
vector<vector<ll>> adj;

ll dfs(ll i){
    if(adj[i].size() == 0){
        return v[i];
    }
    ll mini = LLONG_MAX;  
    for(auto j: adj[i]){
        ll val = dfs(j);
        mini = min(mini, val);
    }
    if(i == 1){
        return mini;
    }
    ll diff = mini - v[i];
    if(diff < 0) return mini;
    else return (diff / 2 + v[i]);
}

void solve(){
    ll n; cin >> n;
    v.resize(n + 1); 
    for(int i = 1; i <= n; i++) 
        cin >> v[i];
    
    adj.resize(n + 1);
    for(int i = 2; i <= n; i++){
        ll x; cin >> x; 
        adj[x].push_back(i);
    }
    
    ll val = dfs(1);
    cout << val + v[1] << endl;

    v.clear();
    adj.clear();
}

int main(){
    ios::sync_with_stdio(0); 
    cin.tie(0);
    
    ll t; 
    cin >> t;
    while(t-- > 0){
        solve();
    }
}
