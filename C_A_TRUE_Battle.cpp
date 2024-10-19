#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n; cin >> n;
    string s; cin >> s;
    if(s[0] == '1' || s[s.size() - 1] == '1'){
        cout << "YES" << endl;
        return;
    }
    for(int i = 0; i < n - 1; i++){
        if(s[i] == '1' && s[i + 1] == '1'){
            cout << "YES" << endl;
            return;
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