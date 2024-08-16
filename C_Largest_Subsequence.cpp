#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool comp(pair<char,int> p1, pair<char,int> p2){
    if(p1.first == p2.first){
        return p1.second < p2.second;
    }
    return p1.first > p2.first;
}
void solve() {
    ll n;
    cin >> n;
    string s;
    cin >> s;
    vector<pair<char,int>> v;
    for(int i = 0; i < s.size(); i++) {
        v.push_back({s[i], i});
    }
    sort(v.begin(), v.end(),comp);

    int prev = -1;
    vector<pair<char,int>> v1;
    for(auto& [i, j] : v) {
        if(j > prev) {
            v1.push_back({i, j});
            prev = j;
        }
    }
    int e = v1.size()-1;
    int dup = 0;
    char c = v1[0].first;
    for(auto& i: v1){
        if(i.first == c){
            dup++;
        }
    }
    for(int i = 0; i < v1.size(); i++) {
        s[v1[i].second] = v1[e].first;
        e--;
    }
    if(is_sorted(s.begin(), s.end())) {
        cout << v1.size() - dup << endl;
    } else {
        cout << -1 << endl;
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll t;
    cin >> t;
    while(t-- > 0) {
        solve();
    }
}
