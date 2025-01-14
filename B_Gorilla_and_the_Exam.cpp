#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    ll n, k; cin >> n >> k;
    map<ll, ll> mp;
    for (int i = 0; i < n; i++) {
        ll x; cin >> x;
        mp[x]++;
    }
    
    multiset<ll> s;
    for (auto& i : mp) {
        s.insert(i.second);
    }

    vector<ll> to_remove;
    for (auto i : s) { 
        if (i <= k) {
            to_remove.push_back(i);
            k -= i;
        }
    }
    for (ll val : to_remove) {
        s.erase(s.find(val));
    }

    if (s.empty()) {
        cout << 1 << endl;
        return;
    }
    
    cout << s.size() << endl;
}

int main() {
    ll t; cin >> t;
    while (t--) {
        solve();
    }
}
