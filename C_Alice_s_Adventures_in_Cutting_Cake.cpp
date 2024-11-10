#include<bits/stdc++.h>
using namespace std;
#define ll long long
typedef vector<ll> vi;

void solve(){

    ll n, m, v;
    cin >> n >> m >> v;
    vi a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    ll S = 0;
    for(auto &i: a) S += i;

    vi sum_front(m + 1, 1e18);
    vi last_end(m + 1, -1);
    sum_front[0] = 0;
    last_end[0] = -1;
    
    ll l = 0;
    ll current_sum = 0;
    for (ll k = 1; k <= m; ++k) {
        if (l >= n) {
            sum_front[k] = 1e18;
            last_end[k] = n;
            continue;
        }
        ll r = l;
        current_sum = 0;
        while (r < n && current_sum < v) {
            current_sum += a[r];
            r++;
        }
        if (current_sum >= v) {
            sum_front[k] = sum_front[k - 1] + current_sum;
            last_end[k] = r - 1;
            l = r;
        } else {
            sum_front[k] = 1e18;
            last_end[k] = n;
        }
    }
    
    // Assign from end
    vi sum_end(m + 1, 1e18);
    vi first_start(m + 1, n);
    sum_end[0] = 0;
    first_start[0] = n;
    
    ll r_ptr = n - 1;
    current_sum = 0;
    for (ll k = 1; k <= m; ++k) {
        if (r_ptr < 0) {
            sum_end[k] = 1e18;
            first_start[k] = -1;
            continue;
        }
        ll l_ptr = r_ptr;
        current_sum = 0;
        while (l_ptr >= 0 && current_sum < v) {
            current_sum += a[l_ptr];
            l_ptr--;
        }
        if (current_sum >= v) {
            sum_end[k] = sum_end[k - 1] + current_sum;
            first_start[k] = l_ptr + 1;
            r_ptr = l_ptr;
        } else {
            sum_end[k] = 1e18;
            first_start[k] = -1;
        }
    }
    
    ll max_Alice = -1;
    for (ll k = 0; k <= m; ++k) {
        if (sum_front[k] != 1e18 && sum_end[m - k] != 1e18) {
            if (k == 0 || m - k == 0 || last_end[k] < first_start[m - k]) {
                ll sum_assigned = sum_front[k] + sum_end[m - k];
                max_Alice = max(max_Alice, S - sum_assigned);
            }
        }
    }
    
    if (max_Alice >= 0) {
        cout << max_Alice << '\n';
    } else {
        cout << "-1\n";
    }

}

int main(){
    ll t; 
    cin >> t;
    while(t--){
        solve();
    }
}