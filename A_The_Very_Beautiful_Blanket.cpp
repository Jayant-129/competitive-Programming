#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n,m; cin >> n >> m;
    ll num = 0;
    vector<vector<ll>> v(n,vector<ll>(m,0));
    for(int i = 0; i < n; i ++){
        ll num = i + 1;
        for(int j = 0; j < m; j ++){
            v[i][j] = num + 512;
            num = v[i][j];
        }
    }
    cout << n* m << endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << v[i][j] << " " ;
        }
        cout << endl;
    }
}
int main(){
  ll t; cin >> t;
  while(t--){
    solve();
  }
}