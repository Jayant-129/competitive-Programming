#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    ll t;
    cin >> t;
    while(t--){
        ll n, x, y;
        cin >> n >> x >> y;
        
        vector<ll> a(n);
        for(auto &num : a) cin >> num;
        
        // Calculate the total sum of the sequence
        ll sum_total = 0;
        for(auto num : a) sum_total += num;
        
        // Sort the sequence to enable binary search
        sort(a.begin(), a.end());
        
        ll count = 0;
        for(int i = 0; i < n; i++){
            ll lower = sum_total - y - a[i];
            ll upper = sum_total - x - a[i];
            auto left = lower_bound(a.begin() + i + 1, a.end(), lower);
            auto right = upper_bound(a.begin() + i + 1, a.end(), upper);
        
            count += distance(left, right);
        }
        
        cout << count << "\n"; 
    }
}