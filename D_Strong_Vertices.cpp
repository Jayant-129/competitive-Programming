#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n;
    cin >> n;
    vector<pair<ll,ll>> v(n + 1);
    for(int i = 1; i <= n; i++){
        ll x;
        cin >> x;
        v[i] = {x , i};
    }
    for(int i = 1; i <= n; i++){
        ll x;
        cin >> x;
        v[i].first -= x;
    }
    sort(v.begin() + 1,v.end(), greater<pair<ll,ll>>());
    ll prev = v[1].first;
    vector<ll> ans;
    for(int i = 1; i <= n; i++){
        if(v[i].first == prev){
            ans.push_back(v[i].second);
        }
        else{
            break;
        }
    }
    sort(ans.begin(),ans.end());
    cout << ans.size() << endl;
    for(auto& i: ans){
        cout << i << " ";
    }
    cout << endl;
}

int main(){
  ll t;
  cin >> t;
  while(t-- > 0){
    solve();
  }
}