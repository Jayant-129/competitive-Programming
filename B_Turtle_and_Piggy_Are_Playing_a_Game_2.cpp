#include<bits/stdc++.h>
using namespace std;
#define ll long long
map<pair<int, int>, string> mp;

string dp(string a, int i, int j) {
    if ((i + 1) == j) {
        return a.substr(0, i + 1);
    }
    if (i == 0) {
        return a.substr(i, 1); 
    }
    if (mp.find({i, j}) != mp.end()) {
        return mp[{i, j}];
    }
    string ans1 = ""; 
    if (j != 1) {
        ans1 = dp(a, i - 1, j - 1) + a[i]; 
    } else {
        ans1 += a[i];
    }
    string ans2 = dp(a, i - 1, j);
    return mp[{i, j}] = (ans1 > ans2) ? ans1 : ans2;
}

vector<string> solve(string s) {
    vector<string> ans;
    int n = s.size();
    for (int i = 1; i <= n; i++) {
        string f = dp(s, n - 1, i);
        ans.push_back(f);
    }
    return ans;
}

int main() {
    string a;
    cin >> a;
    vector<string> ans = solve(a);
    for (auto& i : ans) {
        cout << i << endl;
    }
    return 0;
}
