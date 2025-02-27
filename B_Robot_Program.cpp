#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n, x, k; cin >> n >> x >> k;
    string s; cin >> s;
    ll time = 0, cnt = 0;
    for(int i = 0; i < n; i++){
        time++;
        if(s[i] == 'L'){
            x--;
        }
        else{
            x++;
        }
        if(x == 0){
            k -= time;
            cnt++;
            break;
        }
    }
    if(cnt == 0){
        cout << 0 << endl;
        return;
    }
    
    bool flag = false;
    time = 0;
    for(int i = 0; i < n; i++){
        time++;
        if(s[i] == 'L'){
            x--;
        }
        else{
            x++;
        }
        if(x == 0){
            flag = true;
            break;
        }
    }
    if(flag){
        ll val = k/time;
        cnt += val;
    }
    cout << cnt << endl;
}

int main(){
  ll t; cin >> t;
  while(t--){
    solve();
  }
}