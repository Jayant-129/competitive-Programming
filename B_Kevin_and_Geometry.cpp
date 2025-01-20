#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n; cin >> n;
    vector<ll> v(n); for(auto& x: v) cin >> x;
    sort(v.begin(),v.end());
    if(v[0] == v[1]){
        for(int i = 2; i < (n - 1); i++){
            if(v[i + 1] < (v[0] + v[1] + v[i])){
                cout << v[i + 1] << " " << v[0] << " " << v[1] << " " << v[i] << endl;
                return;
            }
        }
    }
    if(v[1] == v[2]){
        for(int i = 3; i < (n - 1); i++){
            if(v[i + 1] < (v[1] + v[2] + v[i])){
                cout << v[i + 1] << " " << v[1] << " " << v[2] << " " << v[i] << endl;
                return;
            }
        }
        if(v[3] < (v[0] + v[1] + v[2])){
            cout << v[2] << " " << v[0] << " " << v[1] << " " << v[3] << endl;
            return;
        }
    }
    for(int i = 2; i < (n - 1); i++){
        if(v[i] == v[i + 1]){
            cout << v[i + 1] << " " << v[i - 1] << " " << v[i - 2] << " " << v[i] << endl;
            return;
        }
    }
    cout << -1 << endl;
    return;

}
int main(){
  ll t; cin >> t;
  while(t--){
    solve();
  }
}