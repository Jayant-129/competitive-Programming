#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    string s, l, r;
    int m;
    cin >> s >> m >> l >> r;
    vector<vector<int>> v(10);

    for (int i = 0; i < s.size(); i++){
        int j = s[i] - '0';
        v[j].push_back(i);
    }

    for (int i = 0; i < 10; i++) {
        v[i].push_back(s.size());
    }

    int maxi = -1;
    for (int k = 0; k < m; k++) {
        int low = l[k] - '0';
        int high = r[k] - '0';
        int idx = 0;
        for (int i = low; i <= high; i++) {
            auto it = upper_bound(v[i].begin(), v[i].end(), maxi);
                if (*it == s.size()) {
                    cout << "YES" << endl;
                    return; 
                }
                idx = max(idx, *it);
        }
        maxi = idx;
    }

    cout << "NO" << endl;
}

int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}
