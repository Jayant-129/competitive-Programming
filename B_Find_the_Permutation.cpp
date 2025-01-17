#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n; cin >> n;
    vector<vector<ll>> adj(n + 1);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            char x; cin >> x;
            if(x == '1') adj[i].push_back(j);
        }
    }
    vector<ll> ans(n + 1,-1);
    for(int i = 1; i <= n; i++){
        ll cnt = 0;
        for(auto& j: adj[i]){
            if(j > i){
                cnt++;
            }
        }
        ll idx = i;
        for(int i = n; i > 0; i--){
            if(cnt == 0){
                idx = i;
            }
            if(ans[i] == -1){
                cnt--;
            }
        }
        while(ans[idx] != -1) idx--;
        ans[idx] = i;
    }
    for(int i = 1; i <= n; i++){
        cout << ans[i] << " ";
    }
    cout << endl;
}

int main(){
  ll t; cin >> t;
  while(t--){
    solve();
  }
}