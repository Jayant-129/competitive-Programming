#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
const ll MOD = 998244353;
 
// fast modular exponentiation
ll modExp(ll base, ll exp, ll mod){
    ll res = 1;
    base %= mod;
    while(exp){
        if(exp & 1)
            res = (res * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return res;
}
 
// We'll precompute power2 and inv2 arrays up to MAXP.
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    // Since the maximum total n over test cases is <= 2e5,
    // we can precompute up to maxN = 200005.
    const int maxN = 200005;
    vector<ll> power2(maxN+1), inv2(maxN+1);
    power2[0] = 1;
    for (int i = 1; i <= maxN; i++){
        power2[i] = (power2[i-1] * 2) % MOD;
    }
    // Inverse of 2^i is modExp(2^i, MOD-2, MOD)
    for (int i = 0; i <= maxN; i++){
        inv2[i] = modExp(power2[i], MOD-2, MOD);
    }
    cout << inv2[2] << endl;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i=0; i<n; i++){
            cin >> a[i];
        }
        
        // We need at least one 1 and one 3 and at least one 2 in between.
        // Precompute prefix count of 2's.
        vector<int> prefix(n+1, 0);
        for (int i=0; i<n; i++){
            prefix[i+1] = prefix[i] + (a[i] == 2);
        }
        
        ll ans = 0;

        ll S = 0, cnt = 0;
        for (int i=0; i<n; i++){
            if(a[i] == 1){
                S = (S + inv2[prefix[i+1]]) % MOD;
                cnt++;
            }
            else if(a[i] == 3){
                int t = prefix[i];
                ll cur = ( (power2[t] * S) % MOD - cnt ) % MOD;
                if(cur < 0) cur += MOD;
                ans = (ans + cur) % MOD;
            }
        }
        cout << ans % MOD << "\n";
    }
    
    return 0;
}