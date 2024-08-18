#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n;
    cin >> n;
    vector<string> s(2);
    for(int i = 0; i < 2; i++){
        cin >> s[i];
    }
    ll cnt = 0;
    for(int i = 1; i < n; i++){
        if(s[1][i-1] == 'x' && s[1][i+1] == 'x' && s[0][i-1] =='.' && s[0][i+1] == '.' && s[1][i] == '.' && s[0][i] == '.'){
            cnt++;
        }
        if(s[0][i-1] == 'x' && s[0][i+1] == 'x' && s[1][i-1] =='.' && s[1][i+1] == '.' && s[1][i] == '.' && s[0][i] == '.'){
            cnt++;
        }
    }
    cout << cnt << endl;
}

int main(){
  ll t;
  cin >> t;
  while(t-- > 0){
    solve();
  }
}