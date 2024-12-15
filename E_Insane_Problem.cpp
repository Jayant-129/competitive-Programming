#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--){
        ll k, l1, r1, l2, r2;
        cin >> k >> l1 >> r1 >> l2 >> r2;
        
        ll count = 0;
        ll v = 1;
        
        while(v <= r2){
            ll x_min = max(l1, (l2 + v - 1) / v);
            ll x_max = min(r1, r2 / v);
            
            if(x_min <= x_max){
                count += (x_max - x_min + 1);
            }
            if(v > 1e18 / k){
                break;
            }
            v *= k;
        }
        
        cout << count << "\n";
    }
    
    return 0;
}