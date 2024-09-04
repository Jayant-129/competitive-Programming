#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n , x ,y;
    cin >> n >> x >> y;
    vector<ll> v(n + 1, -1);
    bool flag = false;
    for(int i = y - 1; i > 0; i--){
        if(flag){
            v[i] = 1;
        }
        else{
            v[i] = -1;
        }
        flag = !flag;
    }
    flag = false;
    for(int i = x + 1; i <= n; i++){
        if(flag){
            v[i] = 1;
        }
        else{
            v[i] = -1;
        }
        flag = !flag;
    }
    for(ll i = y; i <= x; i++){
        v[i] = 1;
    }
    for(ll i = 1;i <= n; i++){
        cout << v[i] << " ";
    }
    cout << endl;
}

int main(){
  ll t;
  cin >> t;
  while(t-- > 0){
    solve();
  }
}