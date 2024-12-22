#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    ll t;
    cin >> t;
    while(t--){
        ll n, a, b, c;
        cin >> n >> a >> b >> c;
        
        ll s = a + b + c; // Total distance covered in one cycle of 3 days
        ll full_cycles = 0;
        ll total_days = 0;
        
        if(s != 0){
            full_cycles = n / s;
            total_days = full_cycles * 3;
        }
        
        ll remaining = n % s;
        
        if(remaining == 0){
            if(full_cycles > 0){
                cout << total_days << "\n";
            }
            else{
                // If n is 0, no days are needed. However, based on problem constraints, n >=1
                // So, if n ==0, still 0 days.
                cout << "0\n";
            }
            continue;
        }
        
        // Determine the day on which Monocarp completes his journey in the current cycle
        if(remaining <= a){
            total_days += 1;
        }
        else if(remaining <= a + b){
            total_days += 2;
        }
        else{
            total_days += 3;
        }
        
        cout << total_days << "\n";
    }
}