#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<vector<ll>> adj;
ll dfs(ll i,ll mid,ll& val,ll par,ll k){
    ll cnt = 1;
    for(auto& j: adj[i]){
        if(j != par){
            cnt += (dfs(j,mid,val,i,k));
        }
    }

    if(i == 1){
        return cnt;
    }
    else if(val < k && cnt >= mid){
        val++;
        return 0;
    }
    else{
        return cnt;
    }
}
bool good(ll mid,ll k){
    ll val = 0;
    ll cnt = dfs(1,mid,val,-1,k);
    //if(mid == 3) cout << cnt << " " << "YES"<< endl;
    return (cnt >= mid && (val >= (k)));
}
void solve(){
    ll n ,k ; cin >> n >> k;
    adj.clear();
    adj.resize(n + 1);
    for(int i = 1; i < n; i++){
        ll x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    ll l = 1, r = n + 1;
    while(l + 1 < r){
        ll mid = l + (r - l)/2;
        //cout << good(mid,k) <<  " " << mid << endl;
        if(good(mid,k)){
            l = mid;
        }
        else{
            r = mid;
        }
    }
    cout << l << endl;
}

int main(){
  ll t; cin >> t;
  while(t--){
    solve();
  }
}