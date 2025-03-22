#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 998244353;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; 
    cin >> t;
    while(t--){
        int n, m, k, q;
        cin >> n >> m >> k >> q;
        vector<int> xs(q), ys(q);
        for (int i = 0; i < q; i++){
            cin >> xs[i] >> ys[i];
        }
        int ans = 1;
        set<int> ux, uy;
        for (int i = q - 1; i >= 0; i--){
            bool updated = false;
            if(ux.find(xs[i]) == ux.end()){
                ux.insert(xs[i]);
                updated = true;
            }
            if(uy.find(ys[i]) == uy.end()){
                uy.insert(ys[i]);
                updated = true;
            }
            if(updated) {
                ans = (1LL * ans * k) % MOD;
            }
            if(ux.size() == size_t(n) || uy.size() == size_t(m))
                break;
        }
        cout << ans << "\n";
    }
    return 0;
}