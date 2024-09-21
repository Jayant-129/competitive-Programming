#include<bits/stdc++.h>
using namespace std;
#define ll long long

bool good(ll mid, long double avg, vector<ll>& v) {
    ll n = v.size();
    avg += (long double)mid / n;
    ll cnt = 0;
    
    for (ll i = 0; i < n; i++) {
        if ((long double)v[i] < avg / 2.0) { 
            cnt++;
        }
    }

    ll half = n / 2 + 1;
    return cnt >= half;
}

void solve() {
    ll n;
    cin >> n;
    vector<ll> v(n, 0);
    long double sum = 0;
    
    for (auto& x : v) {
        cin >> x;
        sum += (long double)x;
    }

    if (n == 1 || n == 2) {
        cout << -1 << endl;
        return;
    }

    long double avg = sum / n;
    ll cnt = 0;
    
    for (int i = 0; i < n; i++) {
        if ((long double)v[i] < avg / 2.0) {
            cnt++;
        }
    }

    if (cnt >= (n / 2 + 1)) {
        cout << 0 << endl;
        return;
    }

    ll l = 0, r = 1e15;
    while (l + 1 < r) {
        ll mid = l + (r - l) / 2;
        if (good(mid, avg, v)) {
            r = mid;
        } else {
            l = mid;
        }
    }

    cout << r << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}
