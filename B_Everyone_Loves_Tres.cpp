#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n; cin >> n;
    if(n == 1 || n == 3){
        cout << -1 << endl;
        return;
    }
    string s = "";
    n = n - 2;
    for(int i = 0; i < n; i++){
        s += "3";
    }
    if(s.length() >= 2 && n % 2){
        s[s.length() - 2] = '6';
    }
    s = s + "66";
    cout << s << endl;

}
int main(){
  ll t; cin >> t;
  while(t--){
    solve();
  }
}