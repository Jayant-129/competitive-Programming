#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll> f(ll l, ll r){
    vector<ll> ans(r - l + 1, 0);
    cout << "? " << l + 1 << " " <<  r + 1 << endl;
    for(auto& i: ans){
        cin >> i;
        i = i - 1;
    }
    return ans;
}
void solve(){
    ll n; cin >> n;
    ll l = 0,  r = n - 1;
    while(l < r){
        ll mid = l + (r - l)/2;
        vector<ll> curr = f(l, mid);
        bool flag = false;ll cnt = 0;
        for(int i = 0; i < curr.size(); i++){
            if(curr[i] >= l && curr[i] <= mid){
                cnt++;
            }
        }
        if(cnt % 2){
            flag = true;
        }
        if(flag){
            r = mid;
        }
        else{
            l = mid + 1;
        }
    }
    cout << "! " << r + 1 << endl;
}
int main(){
  ll t; cin >> t;
  while(t--){
    solve();
  }
}