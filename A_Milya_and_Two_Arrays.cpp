#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n; cin >> n;
    set<ll> s, s1;
    for(int i = 0; i  < n; i++){
        ll x; cin >> x;
        s.insert(x);
    }
    for(int i = 0; i  < n; i++){
        ll x; cin >> x;
        s1.insert(x);
    }
    if(s.size() >= 3 || s1.size() >= 3){
        cout << "YES" << endl;
    }
    else if(s.size() == 2 && s1.size() == 2){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
}

int main(){
  ll t; cin >> t;
  while(t--){
    solve();
  }
}