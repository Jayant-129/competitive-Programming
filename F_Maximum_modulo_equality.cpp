#include <bits/stdc++.h>
using namespace std;

// Define 'll' as a shorthand for 'long long'
#define ll long long

// Correct Macro Definition: Remove '=' and ';'
#define K 25

ll st[K + 1][200001];

// Function to build the Sparse Table for GCD queries
void build_sparse_table(const vector<ll>& v) {
    int n = v.size();
    
    // Initialize level 0 of the Sparse Table
    for(int j = 0; j < n; j++) {
        st[0][j] = v[j];
    }
    
    // Build the Sparse Table for higher levels
    for(int i = 1; i <= K; i++) {
        for(int j = 0; j + (1 << i) <= n; j++) {
            st[i][j] = __gcd(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
        }
    }
}

// Function to perform GCD queries on the Sparse Table
ll query_gcd(int L, int R) {
    // Calculate the largest power of 2 that fits in the range length
    int length = R - L + 1;
    int k = 0;
    while((1 << (k + 1)) <= length) {
        k++;
    }
    
    // Compute GCD of the two intervals that cover [L, R]
    return __gcd(st[k][L], st[k][R - (1 << k) + 1]);
}

void solve(){
    ll n, q;
    cin >> n >> q;
    
    // Read the sequence 'a'
    vector<ll> a(n, 0);
    for(auto& i: a) cin >> i;
    
    vector<ll> v;
    v.reserve(n - 1);
    for(int i = 0; i < n - 1; i++) {
        v.push_back(abs(a[i] - a[i + 1]));
    }
    
    // If there are no differences, handle queries accordingly
    if(v.empty()) {
        while(q--) {
            ll L, R;
            cin >> L >> R;
            cout << "0" << " ";
        }
        cout << endl;
        return;
    }

    build_sparse_table(v);
    
    // Process each query
    while(q--){
        ll L, R;
        cin >> L >> R;
        
        // Adjust indices to 0-based indexing
        // Assuming input L and R are 1-based and refer to the original array 'a'
        // Thus, differences are from index L-1 to R-2 in 'v'
        // Handle cases where L == R separately
        if(L == R){
            cout << "0" << " ";
            continue;
        }
        
        // Calculate the corresponding indices in the differences array 'v'
        ll start = L - 1;
        ll end = R - 2;
        
        // Ensure the indices are within bounds
        start = max(0LL, start);
        end = min((ll)(v.size() - 1), end);
        
        // Perform the GCD query using the Sparse Table
        ll gcd_result = query_gcd(start, end);
        
        // Output the result
        cout << gcd_result << " ";
    }
    cout << endl;
}

int main(){
    ios::sync_with_stdio(false); // Disable synchronization between C and C++ I/O
    cin.tie(0);                  // Untie cin from cout for faster input
    
    ll t;
    cin >> t;
    while(t--){
        solve();
    }
}