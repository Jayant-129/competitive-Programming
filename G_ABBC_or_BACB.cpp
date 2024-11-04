#include<bits/stdc++.h>
using namespace std;
#define ll long long


void solve(){
    string s; cin >> s;
    ll mini = INT_MAX;
    ll cnt = 0, cntg = 0;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == 'A'){
            cnt++;
            cntg++;
        }
        else{
            mini = min(mini,cnt);
            cnt = 0;
        }
    }
    mini = min(mini,cnt);
    cout << cntg - mini << endl;
}

int main(){
  ll t; cin >> t;
  while(t--){
    solve();
  }
}