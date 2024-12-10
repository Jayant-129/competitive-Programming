#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<pair<ll,ll>> v;
map<int,int> mp;
bool dfs(int i){
    if(i >= v.size()){
        return true;
    }
    if(mp[v[i].first] ||  mp[v[i].second]){
        return false;
    }
    mp[v[i].first] = true;
    mp[v[i].second] = true;
    for(int j = 1; j <= 2; j++){
        int val = i + j + ((i % 2 == 0)? 1:0);
        if(dfs(val)){
            return true;
        }
    }
    return false;
}
void solve(){
    ll n; cin >> n;
    bool ans = true;
    for(int i = 0; i < n; i++){
        ll x, y; cin >> x >> y;
        if(x == y){
            ans = false;
        }
        v.push_back({min(x,y),max(x,y)});
    }
    if(!ans){
        cout << "NO" << endl;
        return;
    }
    sort(v.begin(),v.end());
    bool flag = dfs(0);
    if(flag){  
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
    v.clear();
    mp.clear();
}

int main(){
  ll t; cin >> t;
  while(t--){
    solve();
  }
}