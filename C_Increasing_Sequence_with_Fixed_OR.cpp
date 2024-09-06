#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    ll n;
    cin >> n;
    vector<ll> ans;
    for(ll i = 63 ; i >= 0; i--){
        if(n & (1LL << i)){
            if((n ^ (1LL << i))){
                ans.push_back(n ^ (1LL << i));
            }
        }
    }
    ans.push_back(n);
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