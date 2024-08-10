#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    string s;
    cin >> s;
    queue<pair<ll, string>> q;
    q.push({0, s});
    set<string> s1;
    ll ans = 0;
    while (!q.empty()) {
        auto it = q.front();
        q.pop();
        ll dist = it.first;
        string curr = it.second;
        if (curr == "atcoder") {
            ans = dist;
            break;
        }
        ll size = curr.size();
        for (ll i = 0; i < (size - 1); i++) {
            swap(curr[i], curr[i + 1]);
            if (s1.find(curr) == s1.end()) {
                s1.insert(curr);
                q.push({dist + 1, curr});
            }
            swap(curr[i], curr[i + 1]);
        }
    }
    cout << ans << endl;
}