#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll> v;

void solve() {
    ll n, k;
    cin >> n >> k;
    v.resize(n); 
    for (auto &x : v) cin >> x;
    if(n == 1){
        cout << min(v[0],k) << endl;
        return;
    }
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    for (auto &x : v) pq.push(x);
    
    ll ops = 0;
    ll beg = 0;
    
    while (k > 0 && !pq.empty()) {
        ll m = pq.size();
        ll curr = pq.top();
        pq.pop();
        ll count = 1;
        
        while (!pq.empty() && pq.top() == curr) {
            count++;
            pq.pop();
        }
        
        ll total = (m * (curr - beg)) + (m - count);
        
        if (k >= total) {
            k -= total;
            ops += ((curr - beg + 1) * m);
        } else {
            if (k <= (m * (curr - beg))) {
                ops += k;
                k = 0;
            } else {
                ops += (m * (curr - beg) + count + (k - (m * (curr - beg))));
                k = 0;
            }
        }
        beg += (curr + 1 - beg);
    }
    cout << ops << endl;
    v.clear();
}

int main() {
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
}
