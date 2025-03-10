#include <bits/stdc++.h>
using namespace std;
#define ll long long 

void solve() {
    ll n;
    cin >> n;
    vector<ll> v(2 * n);
    
    for (auto &x : v) cin >> x;
    
    sort(v.begin(), v.end());
    ll sum  = 0;
    for(int i = n + n - 2; i >= 2; i -= 2){
        sum += (v[i] - v[i - 1]);
    }
    sum += (v[2 * n - 1] + v[0]); 
    
    cout << v[2 * n - 1] << " " << sum << " ";
    
    for (int i = 2 * n - 2; i >= 0; i--) 
        cout << v[i] << " ";
    
    cout << endl;
}

int main() {
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
}
