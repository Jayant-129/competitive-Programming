#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<ll> v;
vector<vector<ll>> dp;

ll solve(int i, int j) {
    // Base cases
    if (j < i) {
        return 0;
    }
    if (i == j) {
        return v[i];
    }

    // If already calculated, return stored value
    if (dp[i][j] != -1) {
        return dp[i][j];
    }

    // Recursive relation to calculate maximum difference
    ll ans = max(v[i] - solve(i + 1, j), v[j] - solve(i, j - 1));
    dp[i][j] = ans;  // Store the result in the DP table
    return dp[i][j];
}

int main() {
    ll n;
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    // Initialize DP table with -1 to signify uncalculated states
    dp.resize(n, vector<ll>(n, -1));

    // Calculate the result using the solve function
    ll result = solve(0, n - 1);
    cout << result << endl;

    return 0;
}
