#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    string s; 
    cin >> s;
    deque<char> q;
    for(auto& i: s){
        q.push_back(i);
    }
    string ans = "";
    while(!q.empty()){
        int cnt = min(10, (int)q.size());
        vector<char> v;
        int maxi = INT_MIN, idx = -1;
        for(int i = 0; i < cnt; i++){
            char c = q.front();
            q.pop_front();
            int val = (c - '0') - i;
            if(val > maxi){
                maxi = val;
                idx = i;
            }
            v.push_back(c);
        }
        for(int i = v.size() - 1; i >= 0; i--){
            if(i == idx) continue;
            q.push_front(v[i]);
        }
        ans += (maxi + '0');
    }
    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll t; 
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}