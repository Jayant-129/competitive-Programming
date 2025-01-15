#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<vector<ll>> dp;

ll diff(string& s,ll k, ll j, string& c){
    ll cnt = 0;
    for(ll i = k; i < s.size(); i++){
        if(s[i] != c[i + j]){
            cnt++;
        }
    }
    return cnt;
}
ll dpsolve(string& a,string& b, string& c,ll i, ll j){
    if(i == a.size()){
        return diff(b,j,i,c);
    }
    if(j == b.size()){
        return diff(a,i,j,c);
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    ll ans = INT_MAX;
    if(a[i] == c[i + j]){
        ans = dpsolve(a,b,c,i + 1 , j);
    }
    if(b[j] == c[i + j]){
        ans = min(ans,dpsolve(a,b,c,i , j + 1));
    }
    ans = min(ans, 1 + min(dpsolve(a,b,c,i , j + 1),dpsolve(a,b,c,i + 1 , j)));
    dp[i][j] = ans;
    return dp[i][j];
}
void solve(){
    string a, b, c; cin >> a >> b >> c;
    dp.clear();
    dp.resize(a.size(),vector<ll>(b.size(),-1));
    cout << dpsolve(a,b,c,0,0) << endl;
    // for(int i = 0; i < a.size(); i++){
    //     for(int j = 0; j < b.size(); j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  ll t; cin >> t;
  while(t--){
    solve();
  }
}