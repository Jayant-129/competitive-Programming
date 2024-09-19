#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<vector<char>> v;
string s;ll n;
int dpsolve(int i,char j){
    if(i == n){
        return 0;
    }
    ll ans = 0;

    if(j == '1' && (s[i] == '0' || s[i] == '?')){
        ans = i + dpsolve(i + 1,s[i]);
    }
    else if(j == '0' && (s[i] == '1' || s[i] == '?')){
        ans = i + dpsolve(i + 1,s[i]);
    }
    else{   
        ans = 1 + dpsolve(i + 1,s[i]);
    }
}
void solve(){
    cin >> s; n = s.size();v.resize(n,vector<char>(2,0));
    dp
}

int main(){
  ll t; cin >> t;
  while(t-- > 0){
    solve();
  }
}