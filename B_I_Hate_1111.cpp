#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll> v;
void solve(){
    ll x; cin >> x;
    for(int i = 0; i < 11; i++){
        if(x % 11 == 0){
            cout << "YES" << endl;
            return;
        }
        if(x >= 111){
            x -= 111;
        }
    }
    cout << "NO" << endl;
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  ll t;
  cin >> t;
  while(t-- > 0){
    solve();
  }
}