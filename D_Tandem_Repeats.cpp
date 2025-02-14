#include <bits/stdc++.h>
using namespace std;


bool matchChar(char c1, char c2) {
    return (c1 == '?' || c2 == '?' || c1 == c2);
}

void solve() {
    string s;
    cin >> s;
    int n = (int) s.size();
    int ans = 0;
    for (int d = 1; d * 2 <= n; d++) {
        int curMatches = 0;
        for (int i = 0; i < d; i++) {
            if (matchChar(s[i], s[i + d])) {
                curMatches++;
            }
        }
        if (curMatches == d) {
            ans = max(ans, 2 * d);
        }
        for (int left = 0; left + 2 * d < n; left++) {
            if (matchChar(s[left], s[left + d])) {
                curMatches--;
            }
            if (matchChar(s[left + d], s[left + 2*d])) {
                curMatches++;
            }
            if (curMatches == d) {
                ans = max(ans, 2 * d);
            }
        }
    }

    cout << ans << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;   
    while(t--){
        solve();
    }
    return 0;
}