#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll l ,r;
    cin >> l >> r;
    ll st = l;
    ll i = 1;
    ll cnt = 0;
    while(st <= r){
        st = st + i;
        i++;
        cnt++;
    }
    cout << cnt << endl;
}

int main(){
  ios::sync_with_stdio(0);cin.tie(0);
  ll t;
  cin >> t;
  while(t-- > 0){
    solve();
  }
}