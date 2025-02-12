#include<bits/stdc++.h>
using namespace std;
#define ll long long

bool good(string& s, ll mid, ll k){
    map<char,ll> mp;
    ll n = s.size();
    for(int i = 0; i < mid; i++){
        mp[s[i]]++;
    }
    if(mp.size() == k){
        return true;
    }
    ll st = 0;
    for(int i = mid;  i < n; i++){
        mp[s[i]]++;
        mp[s[st]]--; st++;
        ll cnt = 0;
        for(auto& i: mp){
            if(i.second > 0){
                cnt++;
            }
        }
        if(cnt == k){
            return true;
        }
    }
    return false;
}
int main(){
  ll n; cin >> n; string s; cin >> s;
  map<char,bool> mp;
  for(auto& i: s){
    mp[i] = true;
  }
  ll k = mp.size();
  ll l = 0, r = s.size();
  while(l + 1 < r){
    ll mid = l + (r - l)/2;
    if(good(s,mid,k)){
        r = mid;
    }
    else{
        l = mid;
    }
  }
  cout << r << endl;
}