#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n; cin >> n;
    vector<ll> v(n,0);
    for(ll i = 0; i < n; i++){
        cin >> v[i];
    }
    auto it = max_element(v.begin(),v.end());
    ll idx = distance(v.begin(),it);
    if(n % 2 == 0){
        cout << *it + n/2 << endl;
    }
    else{
        if(idx % 2 == 0){
            cout << *it + (n + 1)/2 << endl;
        }
        else{
            ll maxi = 0;
            for(ll i = 0; i < n; i += 2){
                maxi = max(maxi,v[i]);
            }
            cout << max(*it + (n + 1)/2 - 1, maxi + (n + 1)/2) << endl;
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