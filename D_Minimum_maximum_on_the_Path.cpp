#include<bits/stdc++.h>
using namespace std;
#define ll long long
map<pair<int,int>,bool> mp;
bool good(ll& mid ,vector<vector<pair<ll,ll>>>& adj,ll d, ll i,ll& n, vector<ll>& v){
    if(i == n) {
        v.push_back(i);
        return true;
    }
    if(d == 0){
        return  false;
    }
    if(mp.find({i,d}) != mp.end()) return mp[{i,d}];
    bool ans = false;
    for(auto& j: adj[i]){
        ll dest = j.first;
        ll val = j.second;
        if(val <= mid){
            v.push_back(i);
            if(good(mid, adj,d - 1,dest,n,v)){
                ans = true;
                break;
            }
            v.pop_back();
        }
    }
    mp[{i,d}] = ans;
    return ans;
}

void solve(){
    ll n , m ,d; cin >> n >> m >> d;
    vector<vector<pair<ll,ll>>> adj(n + 1);
    for(int i = 0; i < m; i++){
        ll x , y , z;
        cin >> x >> y >> z;
        adj[x].push_back({y,z});
    }
    vector<ll> v;
    ll val = 0;
    if(good(val,adj,d,1,n,v)){
            cout << v.size() - 1 << endl;
        for(auto& i: v){
            cout << i << " ";
        }
        cout << endl;
        return;
    }
    ll l = 0, r = 1e9;
    while(l + 1 < r){
        ll mid = l + (r - l)/2;
        v.clear();
        mp.clear();
        if(good(mid,adj,d,1,n,v)){
            r = mid;
        }
        else{
            l = mid;
        }
    }
    if(r == 1e9){
        cout << -1 << endl;
        return;
    }
    cout << v.size() - 1 << endl;
    for(auto& i: v){
        cout << i << " ";
    }
    cout << endl;
}

int main(){
  ll t = 1;
  while(t-- > 0){
    solve();
  }
}