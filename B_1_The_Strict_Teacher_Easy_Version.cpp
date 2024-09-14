#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n , m , q; cin >> n >> m >> q;
    ll pos1, pos2; cin >> pos1 >> pos2;
    ll pos3; cin >> pos3;
    bool val1 = pos3 - pos1 > 0;
    bool val2 = pos3 - pos2 > 0;
    ll dist = 0;
    if(val1 && val2){
        dist = (n - max(pos1,pos2));
    }
    else if(!val1 && !val2){
        dist = (min(pos1,pos2) - 1);
    }
    else{
        dist = abs(pos1 - pos2)/2;
    }
    cout << dist << endl;
}

int main(){
  ll t;cin >> t;
  while(t-- > 0){
    solve();
  }
}