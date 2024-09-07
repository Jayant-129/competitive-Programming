#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    ll n , m;
    cin >> n >> m;
    vector<ll> adj(n + 1,0);
    for(int i = 0; i < m; i++){
        ll x , y;
        cin >> x >>  y;
        adj[x]++;
        adj[y]++;
    }
    ll cnt = 0;
    for(auto& i: adj){
        if(i == 1){
            cnt++;
        }
    }
    ll x = n - cnt - 1;
    ll y = cnt/x;
    cout << x << " " << y << endl;;
}

int main(){
  ios::sync_with_stdio(0);cin.tie(0);
  ll t;
  cin >> t;
  while(t-- > 0){
    solve();
  }
}