#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll n, k;
    cin >> n >> k;
    vector<ll> v(n + 1, 0);
    for (ll i = 1; i <= n; i++) {
        cin >> v[i];
    }
    for (ll i = 0; i < k; i++) {
        ll x;
        cin >> x;
        ll l = 0, r = n + 1;
        while(l + 1 < r){
            ll mid = l + (r - l)/2;
            if(v[mid] <= x){
                l = mid;
            }
            else{
                r = mid;
            }
        }
        cout << r << endl;
    }
}
