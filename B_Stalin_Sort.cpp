#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll> v;
void solve(){
    ll n; cin >> n;
    v.resize(n);
    for(auto& x: v){
        cin >> x;
    }
    ll mini = INT_MAX;
    for(int i = 0; i < n; i++){
        ll cnt = i;
        for(int j = i + 1; j < n; j++){
            if(v[j] > v[i]){
                cnt++;
            }
        }
        mini = min(cnt,mini);
    }
    cout << mini << endl;
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  ll t; cin >> t;
  while(t--){
    solve();
  }
}