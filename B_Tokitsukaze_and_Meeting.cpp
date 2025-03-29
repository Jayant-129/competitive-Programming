#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n, m; 
    cin >> n >> m;
    vector<char> v(n * m); 
    for(auto &x: v)
        cin >> x;
    reverse(v.begin(), v.end());
    vector<vector<ll>> col; 
    vector<ll> row(n * m, 0);
    vector<ll> prev(m, 0);
    ll cnt = 0;

    for(int i = (n*m) - 1; i >= 0; i -= m){
        vector<ll> curr(m, 0);
        for(int j = i, k = 0; k < m; k++, j--){
            if(v[j] == '1'){
                cnt = m;
            }
            else {
                cnt--;
            }
            if(cnt > 0) {
                row[j] = 1;
            }
            if(j + m < n * m) {
                row[j] += row[j + m];
            }
            if(v[j] == '1') curr[m - 1 - k] = 1;
            curr[m - 1 - k] += prev[m - 1 - k];
        }
        col.push_back(curr);
        prev = curr;
    }
    reverse(col.begin(), col.end());

    vector<ll> ans(n * m, 0);
    int x = 0;
    for(int i = 0; i < n * m; i += m){
        ll cnt = 0;
        for(auto &val: col[x]){
            if(val >= 1)
                cnt++;
        }
        for(int j = i, k = 0; k < m; k++, j++){
            ans[j] = cnt + row[j];
            if(v[j] == '1'){
                col[x][k]--;
                if(col[x][k] == 0){
                    cnt--;
                }
            }
        }
        x++;
    }
    reverse(ans.begin(), ans.end());
    for(auto &val: ans){
        cout << val << " ";
    }
    cout << endl;
}

int main(){
    ll t; 
    cin >> t;
    while(t--){
        solve();
    }
}

//0011