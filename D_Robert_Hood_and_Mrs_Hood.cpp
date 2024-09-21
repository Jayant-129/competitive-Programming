#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    ll n, d, k; 
    cin >> n >> d >> k; 
    ll b = 1, m = 1;
    vector<pair<ll,ll>> v(n + 1,{0,0});
    for (int i = 0; i < k; i++) {
        ll x, y; 
        cin >> x >> y;
        v[x].first++;
        if(y + 1 <= n){
            v[y + 1].second--;
        }
    }
    ll sum = 0;
    for(int i = 1; i <= d; i++){
        sum += v[i].first;
    }
    ll maxi = sum,mini = sum;
    for(int i = 2; i <= (n - d + 1); i++){
        sum += v[i + d - 1].first;
        sum += v[i].second;
        if(maxi < sum){
            b = i;
            maxi = sum;
        }
        if(mini > sum){
            m = i;
            mini = sum;
        }
    }
    cout << b << " " << m << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}
