#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n; cin >> n;
    vector<ll> v(n); for(auto& x: v) cin >> x;
    ll sum = 0;
    for(int i = 0; i < n; i++){
        sum += v[i];
    }
    for(int j = 1; j < n; j++){
        vector<ll> a;
        if((v[v.size() - 1] - v[0]) < (v[0] - v[v.size() - 1])){
            reverse(v.begin(), v.end());
        }
        sum = max(sum,v[v.size() - 1] - v[0]);
        for(int i = 1; i < v.size(); i++){
            a.push_back(v[i] - v[i - 1]);
        }
        v.clear();
        for(auto& i: a) v.push_back(i);
        a.clear();
    }
    cout << sum << endl;
}

int main(){
  ll t; cin >> t;
  while(t--){
    solve();
  }
}