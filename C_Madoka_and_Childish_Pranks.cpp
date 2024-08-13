#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n , m;
    cin >> n >> m;
    vector<vector<ll>> v(n,vector<ll>(m,0));
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < m; j++){
            char x;
            cin >>  x;
            v[i][j] = (x - '0');
        }
    }
    vector<vector<ll>> v1;
    if(v[0][0] == 1){
        cout << -1 << endl;
        return;
    }
    for(ll i = (n-1); i >= 0; i--){
        for(ll j = (m - 1); j >= 0; j--){
            if(v[i][j] == 1){
                ll x = i + 1, y = j + 1;
                if(j == 0){
                    v1.push_back({x-1,y,x,y});
                }
                else{
                    v1.push_back({x,y-1,x,y});
                }
            }
        }
    }
    cout << v1.size() << endl;
    for(auto& i: v1){
        for(auto& j: i){
            cout << j << " ";
        }
        cout << endl; 
    }
}

int main(){
  ll t;
  cin >> t;
  while(t-- > 0){
    solve();
  }
}