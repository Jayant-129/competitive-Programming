#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    string s; cin >> s;
    vector<ll> v(s.size() + 1, -1); v[0] = 1 , v[1] = 1;
    ll cnt = 0;
    for(int i = 0; i < s.size(); i++){
        char x = s[i];
        if(x == '+'){
            cnt++;
            if(v[cnt - 1] == 0){
                v[cnt] = 0;
            }
        }
        else if(x == '-'){
            cnt--;
            if(v[cnt + 1] == 1){
                v[cnt] = 1;
            }
            if(cnt != 0){
                v[cnt + 1] = -1;
            }
        }
        else if(x == '1'){
            if(v[cnt] == -1){
                v[cnt] = 1;
            }
            if(v[cnt] == 0){
                cout << "NO" << endl;
                return;
            }
        }
        else{
            if(v[cnt] == -1){
                v[cnt] = 0;
            }
            if(v[cnt] == 1){
                cout << "NO" << endl;
                return;
            }
        }
    }
    cout << "YES" << endl;
}

int main(){
  ll t; cin >> t;
  while(t--){
    solve();
  }
}