#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n; cin >> n; vector<ll> v;
    v.push_back(0);
    string s; cin >> s;
    for(auto& i: s){
        v.push_back(i - '0');
    }
    map<ll,ll> mp;
    mp[0] = 1;ll sum= 0, cnt = 0;
    for(int i = 1; i <= n; i++){
        sum += v[i];
        ll curr = mp[sum - i];
        cnt += curr;
        mp[sum - i]++;
    }
    cout << cnt << endl;
}

int main(){
  ios::sync_with_stdio(0);cin.tie(0);
  ll t;
  cin >> t;
  while(t-- > 0){
    solve();
  }
}