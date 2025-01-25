#include<bits/stdc++.h>
using namespace std;
#define ll long long

bool good(ll mid){
    ll ans;
    cout << "?" << " " << 1 << " " << mid << endl;
    cin >> ans;
    cout.flush();
    return ans == mid;
}

void solve(){
    ll l = 1, r = 1000;
    while(l + 1 < r){
        ll mid = l + (r - l)/2;
        if(good(mid)){
            l = mid;
        }
        else{
            r = mid;
        }
    }
    cout << "! " <<  l + 1 << endl;
}
int main(){
  ll t; cin >> t;
  while(t--){
    solve();
  }
}