#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n;string s;
    cin >> n >> s;
    map<char,vector<ll>> mp;
    for(int i = 0; i < n; i++){
        mp[s[i]].push_back(i);
    }
    if((mp['N'].size() % 2 ^ mp['S'].size() % 2) || (mp['E'].size() % 2 ^ mp['W'].size() % 2)){
        cout << "NO" << endl;
        return;
    }
    for(auto [i,j]: mp){
        bool flag;
        if(i == 'N' || i == 'S'){
            flag =  true;
        }
        else{
            flag = false;
        }
        for(auto& k : j){
            if(flag){
                s[k] = 'R';
            }
            else{
                s[k] = 'H';
            }
            flag = !flag;
        }
    }
    bool flag1 = false , flag2 = false;
    for(int i = 0; i < n; i++){
        if(s[i] == 'H'){
            flag1 = true;
        }
        else{
            flag2 = true;
        }
        if(flag1 && flag2){
            cout << s << endl;
            return;
        }
    }
    cout << "NO" << endl;
}

int main(){
  ll t;
  cin >> t;
  while(t--){
    solve();
  }
}