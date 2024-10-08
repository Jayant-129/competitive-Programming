#include<bits/stdc++.h>
using namespace std;
#define ll long long
map<pair<ll,ll>,ll> mp;
vector<pair<ll,ll>> v;
ll dpsolve(ll i,ll j){
    if(i == (v.size() - 1)){
        return 1;
    }
    if(mp.find({i,j}) != mp.end()){
        return mp[{i,j}];
    }
    ll l = (j)?v[i-1].second + v[i-1].first:v[i-1].first;
    ll r = v[i + 1].first;
    ll currh = v[i].second , currx = v[i].first;
    ll ans = 0;
    if(l < (currx - currh)){
        ans = max(ans, 1 + dpsolve(i + 1, 0));
    }
    if(r > (currx + currh)){
        ans = max(ans, 1 + dpsolve(i + 1, 1));
    }
    ans = max(ans,dpsolve(i + 1, 0));
    mp[{i,j}] = ans;
    return ans;
}
int main(){
  ll n; cin >> n;  v.resize(n + 1);
  v[0] = {INT_MIN, INT_MIN};
  for(int i = 1; i <= n; i++){
    ll x , y; cin >> x >> y; v[i] = {x,y};
  }
  cout << dpsolve(1,0) << endl;
}