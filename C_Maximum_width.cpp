#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    long long n, m;
    cin >> n >> m;
    
    string s, t;
    cin >> s >> t;
    
    long long j = 0;
    vector<long long> v1, v2;
    
    for (long long i = 0; i < m; i++) {
        while (j < n && s[j] != t[i]) {
            j++;
        }
        v1.push_back(j);
        j++;
    }
    
    j = s.size();
    for (long long i = m - 1; i >= 0; i--) {
        while (j >= 0 && s[j] != t[i]) {
            j--;
        }
        v2.push_back(j);
        j--;
    }
    
    reverse(v2.begin(), v2.end());
    
    long long ans = 1;
    for (long long i = 0; i < v2.size() - 1; i++) {
        ans = max(ans, v2[i + 1] - v1[i]);
    }
    
    cout << ans;
    
    return 0;
}
