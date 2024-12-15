#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n; cin >> n;
    vector<ll> v(n); 
    vector<bool> vis(n + 1);
    for(auto&x : v){
        cin >> x;
        vis[x] = true;
    } 
    map<ll,bool> mp;
    ll k = 1;
    for(int i = 0; i < n; i++){
        if(!mp[v[i]]){
            mp[v[i]] = true;
            cout << v[i] << " ";
        }
        else{
            while(vis[k]){
                k++;
            }
            cout << k << " ";
            k++;
        }
    }
    cout << endl;
}

int main(){
  ll t; cin >> t;
  while(t--){
    solve();
  }
}