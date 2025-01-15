#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n,m,k; cin >> n >> m >> k;
    ll maxi = n * m - 4;
    set<ll> s;
    vector<ll> v(k); for(auto& x: v) cin >> x;
    ll wan = k;
    for(int i = 0;i < k; i++){
        if(v[i] == wan){
            wan--;
        }
        else{
            s.insert(v[i]);
            if(s.size() > maxi){
                cout << "TIDAK" << endl;
                return;
            }
        }
        while(s.find(wan) != s.end()){
            s.erase(wan);
            wan--;
        }
    }
    cout << "YA" << endl;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  ll t; cin >> t;
  while(t--){
    solve();
  }
}