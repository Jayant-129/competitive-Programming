#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll m , n; cin >> n >> m;
    vector<vector<ll>> v(n,vector<ll>(m, 0));
    vector<ll> a(n);
    ll sum = 0;
    for(int i = 0; i < n; i++){
        ll cntl = 0;
        for(int j = 0; j < m; j++){
            cin >> v[i][j];
            if(v[i][j] == 1){
                cntl++;
            }
        }
        a[i] = cntl;
        sum += cntl;
    }
    if(sum % n){
        cout << -1 << endl;
        return;
    }
    ll tar = sum/n;
    vector<ll> vg;
    vector<ll> vl;
    vector<tuple<int, int, int>> ans;
    for(int j = 0; j < m; j++){
        for(int i = 0; i < n; i++){
            if(a[i] < tar && !v[i][j]) vl.push_back(i);
            if(a[i] > tar &&  v[i][j]) vg.push_back(i);
        }
        for(int i = 0; i < min(vl.size(),vg.size()); i++){
            a[vl[i]]++;
            a[vg[i]]--;
            ans.emplace_back(vl[i], vg[i], j);
        }
        vl.clear(); vg.clear();
    }
    cout << ans.size() << endl;
    for(auto& [i,j,k]: ans){
        cout << i + 1 << " " << j + 1 << " " << k + 1 << endl;
    }
}

int main(){
  ll t; cin >> t;
  while(t--){
    solve();
  }
}