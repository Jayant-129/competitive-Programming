#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll m,n;
vector<vector<ll>> v;
bool good(ll mid, bool flag){
    ll s = 0;
    for(ll i = 0; i < n; i++){
        ll a = v[i][0], b = v[i][1], c = v[i][2];
        ll val = a*b+c;
        ll cnt = 0;
        cnt = (mid/val * b);
        if(mid % val != 0){
          ll val2 = mid % val;
          ll poss = val2/a;
          if(poss > b){
            cnt += b;
          }
          else{
            cnt += poss;
          }
        }
        if(flag){
            cout << cnt << " ";
        }
        s+=cnt;
    }
    return s >= m;
}

int main(){
   cin >> m >> n;
   v.resize(n);
   for(ll i = 0; i < n; i++){
     ll t , z ,y;
     cin >> t >> z >> y;
     v[i] = {t, z, y};
   }
   if(m == 0){
    cout <<  0 << endl;
    return 0;
   }
   ll l = 0 , r = (ll)1e11;
    while(l + 1 < r){
      ll mid = l + (r - l)/2;
      if(good(mid,false)){
        r = mid;
      }
      else{
        l = mid;
      }
    }
   cout << r << endl;
   good(r,true);
   cout << endl;
}