#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--){
        long long n, k;
        cin >> n >> k;
        
        // Frequency array: 1-based indexing
        // Since 1 <= x_i <= n, size is n+1
        vector<long long> freq(n + 1, 0);
        for(long long i = 0; i < n; i++){
            long long x;
            cin >> x;
            if(x >=1 && x <=n){
                freq[x]++;
            }
            // If x is outside 1..n, it cannot form a valid pair, so ignore
        }
        
        // Calculate c_max: total possible k-pairs
        long long c_max =0;
        
        // Iterate x from1 to floor(k/2)
        long long upper = k /2;
        for(long long x =1; x <= upper; x++){
            long long y =k -x;
            if(y <1 || y >n){
                continue; // y not in valid range
            }
            if(x < y){
                c_max += min(freq[x], freq[y]);
            }
            else if(x == y){
                c_max += freq[x] /2;
            }
            // x > y is already covered when x <= floor(k/2)
        }
        
        // Number of pairs Alice can remove: m = n /2
        long long m = n /2;
        
        // Final score: min(c_max, m)
        long long final_score = min(c_max, m);
        
        cout << final_score << "\n";
    }
}