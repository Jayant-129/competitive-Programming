#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n , k;
vector<ll> a;
bool good(double val){
    ll s = 0;
    for(int i = 0; i < n; i++){
        s += floor(a[i]/val);
    }
    return s >= k;
}
int main(){
  cin >> n >> k;
  a.resize(n);
  for(int i = 0; i < n; i++) cin >> a[i];
  double l = 0, r = 1e8;
  for(int i = 0; i < 100; i++){
    double mid = l + (r - l)/2;
    if(good(mid)){
        l = mid;
    }
    else{
        r = mid;
    }
  }
  cout << setprecision(20) << l << endl;
}