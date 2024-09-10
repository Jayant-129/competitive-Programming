#include<bits/stdc++.h>
using namespace std;
#define ll long double
ll c;
bool good(ll mid){
    return (mid * mid + sqrt(mid)) <= c;
}

int main(){
  cin >> c;
  ll l = 0;
  ll r = 1e15;
  for(int i = 0; i < 100; i++){
    ll mid = l + (r - l)/2;
    if(good(mid)){
        l = mid;
    }
    else{
        r = mid;
    }
  }
  cout << setprecision(40) << l << endl;
}