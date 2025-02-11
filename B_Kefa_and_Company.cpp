#include<bits/stdc++.h>
using namespace std;
#define ll long long

bool good(ll mid ,vector<pair<ll,ll>> v,ll d){
    ll n = v.size();
    ll st = 0, sum = 0, maxi = 0;
    for(int i = 0; i < n; i++){
        sum += v[i].second;
        while(st <= i && (v[i].first - v[st].first) >= d){
            sum -= v[st].second;
            st++;
        }
        maxi = max(maxi,sum);
    }
    cout << mid << " " << maxi << endl;
    return maxi >= mid;
}

int main(){
  ll n, d; cin >> n >> d;
  vector<pair<ll,ll>> v;
  for(int i = 0; i < n; i++){
    ll x, y; cin >> x >> y;
    v.push_back({x,y});
  }
  sort(v.begin(),v.end());
  ll l = 0;
  ll r = 0;
  for(auto& i: v) r += i.second;r++;
  while(l + 1 < r){
    ll mid = l + (r - l)/2;
    if(good(mid,v,d)){
        l = mid;
    }
    else{
        r = mid;
    }
  } 
  cout << l << endl;
}