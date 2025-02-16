#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n; cin >> n; string curr ; cin >> curr;
    ll cnt = 0;
    string s = "";
    for(int i = 0; i < n; i++){
        int j = i + 1;
        s += curr[i];
        while(curr[j] == curr[i]){
            j++;
        }  
        j--;
        i = j;
    }
    ll i = s.size() - 1;
    while(s[i] == '1'){
        i--;
    }
    if(i != (s.size() - 1)){
        cnt++;
    }
    //cout << cnt << endl;
    for(int j = i; j >= 0; j--){
        if(s[j] == '1'){
            cnt += 2;
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