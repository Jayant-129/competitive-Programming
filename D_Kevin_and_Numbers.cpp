#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n , m; cin >> n >> m;
    multiset<ll> mp , mp2;
    for(int i = 0; i < n; i++){
        ll x; cin >> x;
        mp.insert(x);
    }
    for(int i = 0; i < m; i++){
        ll x; cin >> x;
        if(mp.find(x) != mp.end()){
            mp.erase(mp.find(x));
        }
        else{
            mp2.insert(x);
        }
    }
    if(mp.empty()){
        cout << "Yes" << endl;
        return;
    }
    ll val = mp.size() - mp2.size();
    if(val <= 0){
        cout << "No" << endl;
        return;
    }
    ll cnt = 0;
    while(cnt <= val){
        cnt += mp2.size();
        multiset<ll> mp3; ll a , b;
        for(auto& i: mp2){
            if(i % 2){
                a = (i + 1)/2; b = (i/2);
            }
            else{
                a = i/2 , b = i/2;
            }
            if(mp.find(a) != mp.end()){
                mp.erase(mp.find(a));
            }
            else{
                mp3.insert(a);
            }
            if(mp.find(b) != mp.end()){
                mp.erase(mp.find(b));
            }
            else{
                mp3.insert(b);
            }
        }
        mp2.clear();
        for(auto& i: mp3){
            mp2.insert(i);
        }
        mp3.clear();
        if(mp2.empty() || mp.empty()){
            break;
        }
    }
    if(mp.empty()){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }

}
int main(){
  ll t; cin >> t;
  while(t--){
    solve();
  }
}