#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define M 998244353
vector<vector<int>> adj;
map<int,vector<ll>> mp;
void dfs(int i, int d){
    mp[d].push_back(i);
    for(auto& j: adj[i]){
        dfs(j,d + 1);
    }
}

void solve(){
    ll n; cin >> n;
    mp.clear(); adj.clear();
    adj.resize(n + 1);
    for(int i = 2; i <= n; i++){
        ll x; cin >> x;
        adj[x].push_back(i);
    }
    dfs(1,1);
    int maxDepth = (mp.rbegin()->first);
    vector<ll> dp(n + 1, 1);
    ll prev = 0, sum = 0;
    for(int i = maxDepth; i > 0; i--){
        for(auto j: mp[i]){
            if(i == maxDepth){
                dp[j] = 1;
            }
            else{
                dp[j] = (dp[j] +  prev) % M;
                if(j != 1){
                    for(auto k: adj[j]){
                        dp[j] = (dp[j] - dp[k] + M)  % M;
                    }
                }
            }
            sum = (sum  +  dp[j]) % M;
        }
        prev = sum;
        sum = 0;
    }
    cout << dp[1] << endl;
}

int main(){
  ll t; cin >> t;
  while(t--){
    solve();
  }
}