#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll r; cin >> r;
    ll k = 1; 
    vector<ll> ans;
    while(k * k < (r + 1) * (r +1)){
        ans.push_back(k * k);
        k++;
    }
    ll cnt = 4;
    for(ll i = 1; i <= r; i++){
        ll lower = (r * r) - (i * i);
        ll upper = ((r + 1) * (r + 1)) - (i * i);
        auto it = lower_bound(ans.begin(), ans.end(), upper);
        auto it2 = lower_bound(ans.begin(), ans.end(), lower);
        //cout << upper << " " << *it << " " << lower << " " << *it2 << " ";
        ll val = distance(it2, it);
        //cout << val << endl;
        cnt += (val * 4);
    }
    cout << cnt << endl;
}

int main(){
    ll t; cin >> t;
    while(t--){
        solve();
    }
}