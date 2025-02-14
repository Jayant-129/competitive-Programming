#include <bits/stdc++.h>
using namespace std;

static const long long INF = (long long)1e15;

// Compute 2D prefix sums of a 0-1 matrix to quickly get #1s in any submatrix
struct Prefix2D {
    vector<vector<int>> pref;
    int n, m;

    Prefix2D(int n_, int m_): n(n_), m(m_) {
        pref.assign(n+1, vector<int>(m+1, 0));
    }

    // Build prefix sums from a matrix mat (0/1)
    void build(const vector<vector<int>>& mat){
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                // pref[i+1][j+1] = #1s in rectangle (0..i, 0..j)
                pref[i+1][j+1] = pref[i+1][j] + pref[i][j+1] 
                                 - pref[i][j] + mat[i][j];
            }
        }
    }

    // Returns #1s in submatrix (r1..r2, c1..c2) inclusive
    int getSum(int r1, int c1, int r2, int c2){
        return pref[r2+1][c2+1] - pref[r2+1][c1] 
             - pref[r1][c2+1] + pref[r1][c1];
    }
};

long long gcdLL(long long a, long long b){
    return b == 0 ? llabs(a) : gcdLL(b, a % b);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; 
    cin >> t;
    while(t--){
        int n, m, k;
        cin >> n >> m >> k;

        // Read the height matrix
        vector<vector<long long>> A(n, vector<long long>(m));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> A[i][j];
            }
        }

        // Read types: '0' or '1'
        // We'll store 1 if it's type '1', else 0
        vector<vector<int>> T(n, vector<int>(m));
        for(int i = 0; i < n; i++){
            string row; 
            cin >> row;
            for(int j = 0; j < m; j++){
                T[i][j] = (row[j] == '1');
            }
        }

        // 1) Compute sum0 and sum1
        long long sum0 = 0, sum1 = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(T[i][j] == 0) sum0 += A[i][j];
                else sum1 += A[i][j];
            }
        }
        long long D = sum0 - sum1;

        // 2) Build prefix sums for T to count #1s quickly
        Prefix2D pf(n, m);
        pf.build(T);

        // 3) For each top-left corner of a k×k block, get #1's => #0's => diff
        //    Accumulate gcd of these diffs
        long long g = 0;
        for(int r = 0; r + k <= n; r++){
            for(int c = 0; c + k <= m; c++){
                // #1-labeled squares in submatrix (r..r+k-1, c..c+k-1)
                int ones = pf.getSum(r, c, r + k - 1, c + k - 1);
                int zeros = k*k - ones;
                long long diff = (long long)zeros - ones; 
                // GCD accumulation
                g = gcdLL(g, diff);
            }
        }

        // 4) If g = 0 => no block can change difference => must check if D == 0
        if(g == 0){
            if(D == 0) cout << "YES\n";
            else cout << "NO\n";
            continue;
        }
        // Otherwise, check if g divides D
        // If yes => can achieve sum0 == sum1 => "YES", else => "NO"
        if(D % g == 0) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}