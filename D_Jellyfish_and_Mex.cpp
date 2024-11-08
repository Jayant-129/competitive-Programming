#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n;
    cin >> n;
    
    // Read all input numbers and determine the maximum x to size the frequency vector accordingly
    vector<ll> input(n);
    ll max_x = 0;
    for(int i = 0; i < n; i++){
        cin >> input[i];
        if(input[i] > max_x){
            max_x = input[i];
        }
    }

    // Initialize frequency vector with size (max_x + 1)
    // Only consider x < n as per original condition
    vector<ll> freq(n, 0);  // Since x < n
    for(auto x : input){
        if(x < n){
            freq[x]++;
        }
    }

    // Compute Mex (Minimum Excludant)
    ll initial_mex = 0;
    while(initial_mex < n && freq[initial_mex] > 0){
        initial_mex++;
    }

    // Initialize DP vector for tabulation
    // dp[mex] will store the minimum cost to achieve this mex
    // Initialize all values to a large number except dp[0] = 0
    vector<ll> dp(initial_mex + 1, LLONG_MAX);
    dp[0] = 0;  // Base case: mex = 0 requires no operations

    // Iterate through all possible mex values from 1 to initial_mex
    for(ll mex = 1; mex <= initial_mex; mex++){
        // For each mex, consider all possible i < mex
        for(ll i = 0; i < mex; i++){
            if(freq[i] > 0){
                // Calculate the potential new cost
                // As per the original recursive formula:
                // cost = mex * (freq[i] - 1) + i + dp[i]
                ll current_cost = mex * (freq[i] - 1) + i + dp[i];
                
                dp[mex] = min(dp[mex], current_cost);
            }
        }
    }
    if(dp[initial_mex] == LLONG_MAX){
        cout << "-1\n";
    }
    else{
        cout << dp[initial_mex] << "\n";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while(t--){
        solve();
    }
}