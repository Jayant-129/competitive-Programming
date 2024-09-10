#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
  ll n, k;
  cin >> n >> k;
  vector<ll> v(n,0);
  for(int i = 0; i < n; i++){
    cin >> v[i];
  }
  for(int i = 0; i < k; i++){
    ll x; cin >> x;
    ll l = 0 ,  r = n;
    while(l + 1 < r){
        ll mid = l + (r - l)/2;
        if(v[mid] <= x){
            l = mid;
        }
        else{
            r = mid;
        }
    }
    if(v[l] == x){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
  }
}