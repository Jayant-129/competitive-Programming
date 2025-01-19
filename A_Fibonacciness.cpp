#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--){
        // Read input values: a1, a2, a4, a5
        long long a1, a2, a4, a5;
        cin >> a1 >> a2 >> a4 >> a5;
        
        // Initialize maximum Fibonacciness
        int max_fib = 0;
        
        // Possible choices for a3
        vector<long long> possible_a3 = {a1 + a2, a4 - a2, a5 - a4};
        
        // To avoid duplicate a3 values affecting the result multiple times
        sort(possible_a3.begin(), possible_a3.end());
        possible_a3.erase(unique(possible_a3.begin(), possible_a3.end()), possible_a3.end());
        
        // Iterate over each possible a3 and calculate Fibonacciness
        for(auto& a3 : possible_a3){
            int fib = 0;
            
            // Condition 1: a3 = a1 + a2
            if(a3 == a1 + a2){
                fib++;
            }
            
            // Condition 2: a4 = a2 + a3
            if(a4 == a2 + a3){
                fib++;
            }
            
            // Condition 3: a5 = a3 + a4
            if(a5 == a3 + a4){
                fib++;
            }
            
            // Update maximum Fibonacciness
            max_fib = max(max_fib, fib);
        }
        
        // Additionally, check if setting a3 to a value that doesn't correspond to any of the above can yield a higher Fibonacciness
        // In this problem, it's not necessary as the maximum Fibonacciness achievable is 3, which is already covered.
        
        cout << max_fib << "\n";
    }
}