#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n ,m ; cin >> n >> m;
    vector<vector<char>> v(n,vector<char>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> v[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        bool flag = true;
        for(int j = 0; j < m; j++){
            if(flag && v[i][j] == '1'){
                continue;
            }
            if(flag && v[i][j] != '1'){
                flag =  false;
            }

            if(v[i][j] == '1'){
                ll x = i - 1;
                while(x >= 0){
                    if(v[x][j] != '1'){
                        cout << "NO" << endl;
                        return;
                    }
                    x--;
                }
            }
        }
    }
    cout << "YES" << endl; 

}

int main(){
  ll t; cin >> t;
  while(t--){
    solve();
  }
}