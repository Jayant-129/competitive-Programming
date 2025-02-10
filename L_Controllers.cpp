#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n; cin >> n; ll cnt0=0 ,cnt1 = 0;
    string s; cin >> s;
    for(auto i: s){
        if(i == '+'){
            cnt0++;
        }
        else{
            cnt1++;
        }
    }
    ll q; cin >> q;
    while(q--){
        ll x, y; cin >> x >> y;
        if(y > x) swap(x,y);
        ll val = (cnt1 - cnt0)*y;
        ll deno = x - y;
        if(deno == 0){
            if(cnt1 == cnt0){
                cout << "YES" << endl;
            }
            else{
                cout << "NO" << endl;
            }
            continue;
        }
        if(val % deno){
            cout << "NO" << endl;
            continue;
        }
        ll fin = val/deno;
        if(fin <= cnt0 && fin >= (-1 * cnt1)){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
}

int main(){
  ll t = 1;
  while(t--){
    solve();
  }
}