#include <bits/stdc++.h>
using namespace std;

#ifdef __GNUG__
#include <sys/resource.h>
void increaseStackSize() {
    const rlim_t kStackSize = 64 * 1024 * 1024; // 64 MB
    struct rlimit rlim;
    int result = getrlimit(RLIMIT_STACK, &rlim);
    if(result == 0 && rlim.rlim_cur < kStackSize) {
        rlim.rlim_cur = kStackSize;
        setrlimit(RLIMIT_STACK, &rlim);
    }
}
#endif

const int INF = 1e9;
int n, m;
vector<string> grid;
// Directions: 0: Down, 1: Left, 2: Up, 3: Right.
int dir[4][2] = { {1, 0}, {0, -1}, {-1, 0}, {0, 1} };
char moveL[4] = {'D', 'L', 'U', 'R'};
// dp[i][j][prev] where prev in [0..3] are the last move indices and index 4 indicates "none"
// "$" indicates state not computed; "#" indicates no valid path from that state.
vector<vector<vector<string>>> dp; 

string dfs(int i, int j, int prev) {
    // If we reached target B, return an empty string.
    if (grid[i][j]=='B')
        return "";
    
    // If this state was computed (or is being processed), return stored value.
    if (dp[i][j][prev] != "$")
        return dp[i][j][prev];
    
    // Mark this state as processing (cycle detection):
    dp[i][j][prev] = "#";
    
    string best = "";
    bool found = false;
    
    // Try all moves.
    for (int d = 0; d < 4; d++){
        int ni = i + dir[d][0], nj = j + dir[d][1];
        if (ni < 0 || nj < 0 || ni >= n || nj >= m)
            continue;
        if (grid[ni][nj]=='#')
            continue;
        string candidate = dfs(ni, nj, d);
        if (candidate == "#")  // no valid path from neighbor
            continue;
        candidate = moveL[d] + candidate;
        if (!found || candidate.size() < best.size()){
            best = candidate;
            found = true;
        }
    }
    
    if (!found)
        dp[i][j][prev] = "#";
    else
        dp[i][j][prev] = best;
    
    return dp[i][j][prev];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    #ifdef __GNUG__
    increaseStackSize();
    #endif
    
    cin >> n >> m;
    grid.resize(n);
    for (int i = 0; i < n; i++){
        cin >> grid[i];
    }
    
    int start_i = -1, start_j = -1;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (grid[i][j]=='A'){
                start_i = i; start_j = j;
                break;
            }
        }
        if (start_i != -1)
            break;
    }
    
    // Initialize dp: dimensions n x m x 5 (for prev indices 0..4)
    dp.assign(n, vector<vector<string>>(m, vector<string>(5, "$")));
    // Start DFS from the starting cell with special state 4 indicating no previous move.
    string ans = dfs(start_i, start_j, 4);
    
    if (ans == "#" || ans == "$")
        cout << "NO" << "\n";
    else{
        cout << "YES" << "\n";
        cout << ans.size() << "\n";
        cout << ans << "\n";
    }
    
    return 0;
}