#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n, k; cin >> n >> k;
    vector<ll> a(n); for(auto& x: a) cin >> x;
    vector<ll> b(n); for(auto& x: b) cin >> x;
    ll val = *max_element(b.begin(),b.end());
    if(val != -1){
        ll glb = -1;
        bool flag = true;
        for(int i = 0; i < n; i++){
            if(b[i] != -1){
                ll curr = a[i] + b[i];
                if(glb != -1 && curr != glb) flag = false;
                else glb = curr;
            }
        }
        ll mini = *min_element(a.begin(),a.end());
        ll maxi = *max_element(a.begin(),a.end());
        ll val3 = mini + k;
        cout << (flag && (glb <= val3) && (maxi <= glb) )<< endl;
    }
    else{
        ll maxi = *max_element(a.begin(),a.end());
        ll mini = *min_element(a.begin(),a.end());
        ll ans = max((mini + k - (maxi-1)), 0LL);
        cout << ans << endl;
    }
}

int main(){
  ll t; cin >> t;
  while(t--){
    solve();
  }
}