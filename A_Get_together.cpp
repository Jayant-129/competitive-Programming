#include <bits/stdc++.h>
using namespace std;
#define ll long double

vector<pair<ll, ll>> v; 


bool good(ll mid, ll n) {
    ll mini = 1e18; 
    ll maxi = -1e18; 
    for (int i = 0; i < n; i++) {
        ll val1 = v[i].first - mid * v[i].second;
        ll val2 = v[i].first + mid * v[i].second;
        mini = min(mini, val2);
        maxi = max(maxi, val1);
    }
    return maxi <= mini;
}

int main() {
    ios::sync_with_stdio(0);cin.tie(0);
    ll n;
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++) {
        ll x, y;
        cin >> x >> y;
        v[i] = {x, y}; 
    }

    ll l = 0, r = 1e9; 
    for (int i = 0; i < 100; i++) { 
        ll mid = l + (r - l) / 2;
        if (good(mid, n)) {
            r = mid; 
        } else {
            l = mid; 
        }
    }
    cout << fixed << setprecision(9) << r << endl; 
}
