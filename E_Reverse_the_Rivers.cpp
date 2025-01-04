#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k, q;
    cin >> n >> k >> q;
    // Read the a_i_j values
    vector<vector<int>> a(n, vector<int>(k));
    for(auto &row : a) {
        for(auto &val : row) cin >> val;
    }
    // Compute the b_i_j values
    vector<vector<int>> b(k, vector<int>(n));
    for(int j=0; j<k; ++j){
        int current_or = 0;
        for(int i=0; i<n; ++i){
            current_or |= a[i][j];
            b[j][i] = current_or;
        }
    }
    // For each region j, sort the b[j] array (already non-decreasing)
    // Process each query
    while(q--){
        int m;
        cin >> m;
        // Initialize the constraints
        int overall_max_lower = 1;
        int overall_min_upper = n;
        for(int i=0; i<m; ++i){
            int r;
            char o;
            int c;
            cin >> r >> o >> c;
            r -=1; // 0-based index
            if(o == '<'){
                // Find the last i where b[r][i] < c
                // upper_bound returns first i where b[r][i] >= c
                // So, valid i <= pos-1
                int pos = upper_bound(b[r].begin(), b[r].end(), c-1) - b[r].begin();
                if(pos ==0){
                    // No country satisfies this condition
                    overall_min_upper = -1;
                }
                else{
                    overall_min_upper = min(overall_min_upper, pos);
                }
            }
            else { // o == '>'
                // Find the first i where b[r][i] > c
                // lower_bound returns first i where b[r][i] > c
                int pos = upper_bound(b[r].begin(), b[r].end(), c) - b[r].begin() +1;
                if(pos > n){
                    // No country satisfies this condition
                    overall_max_lower = n+1;
                }
                else{
                    overall_max_lower = max(overall_max_lower, pos);
                }
            }
        }
        if(overall_max_lower <= overall_min_upper && overall_min_upper != -1){
            cout << overall_max_lower << "\n";
        }
        else{
            cout << "-1\n";
        }
    }
}