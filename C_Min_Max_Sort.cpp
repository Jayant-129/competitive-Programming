#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n; cin >> n;
    vector<ll> v(n, 0);
    for(auto& x: v) cin >> x;
    set<ll> s;
    ll ans = 0;
    ll i = 1 , j = n , st = 0 , e = n - 1;
    while(st < e){
        if(s.find(v[st]) != s.end()){
            st++;
            continue;
        }
        if(s.find(v[e]) != s.end()){
            e--;
            continue;
        }
        if(v[st] != i || v[e] != j){
            ans = i;
        }
        s.insert(i);
        s.insert(j);
        i++; j--;
    }
    cout << ans << endl;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  ll t; cin >> t;
  while(t--){
    solve();
  }
}