#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    
    // Initialize the grid
    vector<vector<ll>> v(n, vector<ll>(m, 0));
    
    // Read the grid input
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> v[i][j];
        }
    }
    
    // Identify the path cells
    vector<pair<int, int>> path_cells;
    int r = 0, c = 0;
    path_cells.emplace_back(r, c);
    
    for(char direction : s){
        if(direction == 'D'){
            r++;
        }
        else { // direction == 'R'
            c++;
        }
        path_cells.emplace_back(r, c);
    }
    
    // Traverse the path and adjust the altitudes
    for(int i = 0; i < s.size(); i++){
        // Current cell coordinates
        int current_r = path_cells[i].first;
        int current_c = path_cells[i].second;
        
        // Determine the next step direction
        char next_step = s[i];
        
        if(next_step == 'D'){
            // Calculate the sum of the current row
            ll sum = 0;
            for(int j = 0; j < m; j++){
                sum += v[current_r][j];
            }
            // Set the current cell to the negative sum to make row sum zero
            v[current_r][current_c] = -sum;
        }
        else { // next_step == 'R'
            // Calculate the sum of the current column
            ll sum = 0;
            for(int j = 0; j < n; j++){
                sum += v[j][current_c];
            }
            // Set the current cell to the negative sum to make column sum zero
            v[current_r][current_c] = -sum;
        }
        
        // Update the position based on the current step
        if(next_step == 'D'){
            r++;
        }
        else {
            c++;
        }
    }
    
    // Adjust the last cell on the path
    // This ensures that both its row and column sums are zero
    // Since it's the end, there's no next step, so we handle it separately
    int last_r = path_cells.back().first;
    int last_c = path_cells.back().second;
    
    // Calculate the sum of the last row excluding the path cell
    ll sum_last_row = 0;
    for(int j = 0; j < m; j++){
        if(j != last_c){
            sum_last_row += v[last_r][j];
        }
    }
    
    // Calculate the sum of the last column excluding the path cell
    ll sum_last_col = 0;
    for(int i = 0; i < n; i++){
        if(i != last_r){
            sum_last_col += v[i][last_c];
        }
    }
    
    // Since both row and column should sum to the same value x,
    // and we've set all other rows and columns to sum to zero,
    // we set the last cell to x such that:
    // sum_last_row + x = 0  => x = -sum_last_row
    // sum_last_col + x = 0  => x = -sum_last_col
    // Therefore, sum_last_row should be equal to sum_last_col for consistency
    // (Problem guarantees that a solution exists)
    
    // Assign the last cell
    v[last_r][last_c] = -sum_last_row; // or -sum_last_col
    
    // Output the restored grid
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << v[i][j] << ' ';
        }
        cout << '\n';
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll t; 
    cin >> t;
    while(t--){
        solve();
    }
}