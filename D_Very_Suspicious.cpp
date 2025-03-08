#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll sum(ll n){
    if(n % 2 == 0){
        return (n/2) *(n + 1);
    }
    else{
        return n * ((n + 1)/2);
    }
}
bool good(ll mid, ll n){
    ll x = mid/3 , y= mid/3, z = mid/3;
    if(mid % 3 == 1){
        x++;
    }
    if(mid % 3 == 2){
        x++; y++;
    }
    //cout << mid << " " <<  x << " " <<  y << " " << z << endl;
    ll val = 0;
    val += (4 * (sum(z)));
    if(x > 0) val += (4 * (sum(x - 1)));
    val += (2 * (sum(y)));
    if(y > 0) val += (2 * (sum(y - 1)));
    return val >= n;
}

void solve(){
    ll n; cin >> n;
    ll l = 0 , r = 1e9;
    while(l + 1 < r){
        ll mid = l + (r-l)/2;
        if(good(mid,n)){
            r = mid;
        }
        else{
            l = mid;
        }
    }
    cout << r << endl;
}

int main(){
  ll t; cin >> t;
  while(t--){
    solve();
  }
}