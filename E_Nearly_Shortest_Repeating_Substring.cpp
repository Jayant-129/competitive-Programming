#include<bits/stdc++.h>
using namespace std;
#define ll long long


void solve(){
    ll n; cin >> n;
    string s; cin >> s;
    vector<ll> v;
    for(int i = 1; i * i <= n; i++){
        if(n % i == 0){
            v.push_back(i);
            if(i != (n/i)){
                v.push_back(n/i);
            }
        }
    }
    sort(v.begin(),v.end());
    for(auto i: v){
        vector<string> v1; v1.push_back(s.substr(0,i));v1.push_back(s.substr(n - i));
        for(auto curr: v1){
            ll k = curr.length();
            if(n % k == 0){
                bool flag = true;
                ll cnt = 0;
                for(int j = 0; j < n; j++){
                    if(s[j] != (curr[j % k])){
                        cnt++;
                    }
                    if(cnt > 1){
                        flag = false;
                        break;
                    }
                }
                if(flag){
                    cout << k << endl;
                    return;
                }
            }
        }
    }
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  ll t; cin >> t;
  while(t--){
    solve();
  }
}