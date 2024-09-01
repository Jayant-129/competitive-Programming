#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    ll n;
    cin >> n;
    
    vector<ll> v(n + 1);
    for (ll i = 1; i <= n; i++) {
        cin >> v[i];
    }

    string s;
    cin >> s;
    s = '#' + s;
    vector<bool> vis(n + 1, false);
    vector<ll> ans(n + 1, 0);
    for(int i = 1;i <= n; i++){
        if(!vis[i]){
            int j = i;
            int cnt = 0;
            vector<int> v1;
            while(true){
                if(vis[j]){
                    break;
                }
                if(s[j] == '0'){
                    cnt++;
                }
                vis[j] = true;
                v1.push_back(j);
                j = v[j];
            }
            for(auto& k: v1){
                ans[k] = cnt;
            }
        }
    }
    
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}
int main() {
    ll t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
    return 0;
}
