#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXI 101

vector<vector<ll>> dp(MAXI, vector<ll>(8, 0));
vector<vector<ll>> previous(MAXI, vector<ll>(8, -1));  // -1 indicates no previous state
string s;

void solve(int i) {
    if (i < 0) {
        return;
    }

    dp[i][(s[i] - '0') % 8] = true;
    solve(i - 1);  // Single digit check
    for (int k = 0; k < 8; k++) {
        if (i > 0 && dp[i - 1][k]) {
            // Add current digit to the previously formed number and take modulo 8
            int new_mod = (k * 10 + (s[i] - '0')) % 8;
            dp[i][new_mod] = true;
            previous[i][new_mod] = k;  // Track the previous state
            dp[i][k] = true;           // Maintain the previous state without change
            previous[i][k] = k;
        }
    }

    // Recursive call to fill the DP table for the previous indices
}

int main() {
    cin >> s;
    int n = s.length();
    solve(n - 1);
    for (int i = 0; i < n; i++) {
        if (dp[i][0]) {
            string ans = "";
            int curI = i, curJ = 0;
 
            while (true) {
                if (prev[curI][curJ] == -1 || prev[curI][curJ] != curJ) {
                    ans.append(1, s[curI]);
                }
 
                if (prev[curI][curJ] == -1) break;
 
                curJ = prev[curI][curJ];
                curI--;
            }
 
            puts("YES");
            reverse(all(ans));
            cout << ans << endl;
            return 0;
        }
    }

    cout << "NO" << endl;
    return 0;
}
