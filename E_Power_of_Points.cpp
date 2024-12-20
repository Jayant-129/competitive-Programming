#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n;
    cin >> n;
    vector<ll> v(n);
    for(auto &x: v) cin >> x;

    vector<ll> sorted = v;
    sort(sorted.begin(), sorted.end());

    vector<ll> pre(n, 0);
    pre[0] = sorted[0];
    for(int i = 1; i < n; i++) pre[i] = pre[i - 1] + sorted[i];

    ll sumg = pre[n - 1];

    vector<ll> ans;
    ans.reserve(n);

    for(auto &x: v){
        int pos = upper_bound(sorted.begin(), sorted.end(), x) - sorted.begin();
        ll val = (ll)x * pos - (pos > 0 ? pre[pos - 1] : 0);
        ll val2 = (sumg - (pos > 0 ? pre[pos - 1] : 0)) - (ll)x * (n - pos);
        ll sum = val + val2 + n;
        ans.push_back(sum);
    }
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll t;
    cin >> t;
    while(t--){
        solve();
    }
}
