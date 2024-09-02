#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n, k;
    cin >> n >> k;
    vector<ll> v(n, 0);
    for(ll i = 0; i < n; i++){
        cin >> v[i];
    }
    sort(v.begin(),v.end(), greater<ll>());
    // for(int i = 0; i < n; i++){
    //     cout << v[i] << " ";
    // }
    // cout << endl;
    ll cnt1 = 0, cnt2 = 0, j = 0, prev= -1; bool flag = true;
    for(auto& i: v){
        if(flag){
            cnt1 += i;
            prev = i;
        }
        else{
            ll req = prev - i;
            if(req <= k){
                k -= req;
                i += req;
            }
            else{
                i += k;
                k = 0;
            }
            cnt2 += i;
        }
        flag = !flag;
        //cout << cnt1 << " " << cnt2 << endl;
    }
    cout << cnt1 - cnt2 << endl;
}

int main(){
  ll t;
  cin >> t;
  while(t-- > 0){
    solve();
  }
}