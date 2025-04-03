#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n, k; cin >> n >> k;
    vector<ll> v(n); for(auto& x: v) cin >> x;
    sort(v.begin(),v.end());
    ll sum = 0, cnt = 1, ops = 0;
    for(auto& x: v) sum += x;
    if(sum <= k){
        cout << 0 << endl;
        return;
    }
    for(int i = n - 1; i >= 1; i--){
        ll dec = (v[i] - v[0]);
        if(dec < cnt){
            ll diff = (cnt - dec);
            ll sum2 = sum - (cnt) * diff;
            v[0] -= diff;
            if(sum2 <= k){
                ll val = (((sum - k) + (cnt - 1))/(cnt));
                ops += val;
                cout << ops << endl;
                return;
            }
            ops += diff;
            dec = cnt;
            sum = sum2;
        }
        sum -= dec;
        cnt++;
        ops += 1;
        if(sum <= k){
            cout << ops << endl;
            return;
        }
    }
    if(sum > k){
        ll val = (((sum - k) + (cnt - 1))/(cnt));
        cout << val + ops << endl;
    }
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ll t; cin >> t;
  while(t--){
    solve();
  }
}