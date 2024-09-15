#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<string> v;
vector<vector<int>> dp;
string check = "narek"; ll n , m;
int dpans(int i, int idx){
    if(i == n){
        return -2 * idx;
    }
    if(dp[i][idx] != -10000000){
        return dp[i][idx];
    }
    ll nottake = dpans(i + 1, idx);
    int x = 0, y = 0;
    ll j = idx;
    for(auto& k: v[i]){
        if(k == check[j]){
            x++;
            j = (j + 1)%5;
        }
        else if(k == 'n' || k == 'a' || k == 'r' || k == 'e' || k == 'k'){
            y++;
        }
    }
    ll take = dpans(i + 1, j) + (x - y);
    dp[i][idx] = max(take, nottake);
    return dp[i][idx];
}

void solve(){
    cin >> n >> m;
    v.resize(n);
    dp.clear();
    dp.resize(n,vector<int>(5,-10000000));
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    cout << dpans(0,0) << endl;
}

int main(){
  ll t;cin >> t;
  while(t-- > 0){
    solve();
  }
}