#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n; cin >> n; vector<ll> v(n, 0); ll s1 = 0 ,  s = 0;
    for(int i = 0; i < n; i++){
        cin >> v[i];
        if(i % 2){
            s1 += v[i];
        }
        else{
            s += v[i];
        }
    }
    bool flag = true;
    if(s1 > s){
        flag = false;
    }
    vector<ll> b(n,1);
    for(int i = 0; i < n; i++){
        if(flag && !(i % 2)){
            b[i] = v[i];
        }
        else if(!flag && i % 2){
            b[i] = v[i];
        }
    }
    for(int i = 0; i < n; i++){
        cout << b[i] << " ";
    }
    cout << endl;
}

int main(){
  ios::sync_with_stdio(0);cin.tie(0);
  ll t;
  cin >> t;
  while(t-- > 0){
    solve();
  }
}