#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,x,y;
bool good(ll z){
    return (z/x)+(z/y) >= (n - 1);
}
int main(){
  cin >> n >> x >> y;
  if(n == 1){
    cout << min(x,y) << endl;
    return 0;
  }
  ll l = 0, r = max(x,y)*n;
  ll w = min(x,y);
  while(l + 1 < r){
    ll mid = l + (r-l)/2;
    if(good(mid - w)){
        r = mid;
    }
    else{
        l= mid;
    }
  }
  cout << r << endl;
}