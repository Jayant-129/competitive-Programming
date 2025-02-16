#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<ll> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<ll> prefix(n + 1, 0);
        for(int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i];
            if(a[i] > 0) {
                prefix[i + 1] += a[i];
            }
        }
        vector<ll> suffix(n + 1, 0);
        for(int i = n - 1; i >= 0; i--) {
            suffix[i] = suffix[i + 1];
            if(a[i] < 0) {
                suffix[i] += abs(a[i]);
            }
        }
        
        ll maxCoins = 0;
        for(int i = 0; i <= n; i++) {
            maxCoins = max(maxCoins, prefix[i] + suffix[i]);
        }
        
        cout << maxCoins << "\n";
    }
    
    return 0;
}