#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n, a , b;string s;
    cin >> n >> a >> b; cin >> s;
    ll x = 0, y = 0, cnt = 0;
    for(int i = 0; (i < n) && (cnt < 50); i = (i + 1)% n){
        if(s[i] == 'N'){
            y++;
        }
        else if(s[i] == 'W'){
            x--;
        }
        else if(s[i] == 'E'){
            x++;
        }
        else{
            y--;
        }
        if(x == a && y == b){
            cout << "YES" << endl;
            return;
        }
        if(i == (n - 1)){
            cnt++;
        }
    }
    cout << "NO" << endl;
}

int main(){
  ll t; cin >> t;
  while(t--){
    solve();
  }
}