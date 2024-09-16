#include<bits/stdc++.h>
using namespace std;
#define ll long long
void print(vector<ll>& ans){
    for(int i = 0; i < (ll)ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;
}
void solve(){
    ll n , k , m = 0; cin >> n >> k;
    map<ll,vector<ll>> mp; vector<ll> ans(n,0);
    for(int i = 0; i < n; i++){
        ll x; cin >> x;
        if((ll)mp[x].size() < k){
            mp[x].push_back(i);
            m++;
        }
    }
    m -= (m % k);
    ll color = 0;
    for(auto& i: mp){
        for(auto& j: mp[i.first]){
            ans[j] = ++color;
            color %= k;
            if(--m == 0){
                print(ans);
                return;
            }
        }
    }
}

int main(){
  ll t;
  cin >> t;
  while(t-- > 0){
    solve();
  }
}