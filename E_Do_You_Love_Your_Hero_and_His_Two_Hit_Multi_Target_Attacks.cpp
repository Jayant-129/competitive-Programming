#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll k; cin >> k;
    vector<pair<ll,ll>> ans;
    ll i = 1, j = 1, st = 1, sum = 0;
    while(true){
        if(sum + (j - st) <= k){
            sum += (j - st);
            if(sum == k){
                ans.push_back({i,j});
                break;
            }
        }
        else{
            ll val = k - sum;
            if(val  == 1){
                ans.push_back({1000,1});
                break;
            }
            else if(val == 2){
                ans.push_back({1000,1});
                ans.push_back({1001,2});
                break;
            }
            i++;
            st = j;
        }
        ans.push_back({i,j});
        j++;
    }
    cout << ans.size() << endl;
    for(auto [i,j]: ans){
        cout << i << " " << j << endl;
    }
}

int main(){
  ll t; cin >> t;
  while(t--){
    solve();
  }
}