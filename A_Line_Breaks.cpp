#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll m, n; cin >> m >> n;
    int cnt = 0; bool flag = true;
    while(m--){
        string s; cin >> s;
        int x = s.length();
        if(x <= n && flag){
            n -= x;
            cnt++;
        }
        else{
            flag = false;
            continue;
        }
    }
    cout << cnt << endl;
}

int main(){
  ll t; cin >> t;
  while(t--){
    solve();
  }
}