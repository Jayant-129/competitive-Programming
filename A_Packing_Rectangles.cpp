#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll w , h , n;
bool good(ll x){
    return (x/w)*(x/h)>=n;
}
int main(){
  cin >> w >> h >> n;
  ll l = 0 , r = 1;
  while(!good(r)){
    r *= 2;
  }
  while(l + 1 < r){
    ll mid = l + (r - l)/2;
    if(good(mid)){
        r = mid;
    }
    else{
        l = mid;
    }
  }
  cout << r << endl;
}