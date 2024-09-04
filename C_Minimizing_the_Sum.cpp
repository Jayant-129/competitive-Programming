#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    ll n , k;
    cin >> n >> k;
    vector<ll> v(n + 1, 0);
    for(ll i = 1; i <= n; i++){
        cin >> v[i];
    }
    
    vector<vector<ll>> dp(n + 1, vector<ll>(k + 1, INT_MAX));
    for(int i = 0; i <= k; i++){
        dp[0][i] = 0;
    }

    for(ll i = 1; i <= n; i++){
        for(ll c = 0; c <= k; c++){
            ll mini = INT_MAX;
            for(ll j = i; i - j <= c && j > 0; j--){
                mini = min(v[j],mini);
                ll x = mini * (i - j + 1);
                x += dp[j - 1][c - (i - j)];
                dp[i][c] = min(x,dp[i][c]);
            }
        }
    }

    ll ans = INT_MAX;
    for(ll i = 0; i <= k; i++){
        ans = min(dp[n][i], ans);
    }
    cout << ans << endl;
}

int main() {
    ll t;
    cin >> t;
    while(t-- > 0){
        solve();
    }
    return 0;
}
