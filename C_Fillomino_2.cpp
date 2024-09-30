#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  ll n; cin >> n;
  vector<pair<ll,ll>> v(n + 1,{0,0});
  vector<vector<ll>> ans(n,vector<ll>(n, 0));
  for(int i = 0; i < n; i++){
    ll x; cin >> x;
    v[x] = {i,i};
    ans[i][i] = x;
  }
  vector<ll> freq(n + 1,0);
  for(int i = 1; i <= n; i++) freq[i] = i - 1;
  ll dir[4][2] = {{0,-1}, {1,0},{-1,0}, {0,1}};
  ll ops = ((n - 1) * n)/2;
  for(int i = 0; i < ops; i++){
    for(int j = 1; j <= n; j++){
        ll cnt = 0;
        ll idx1 = v[j].first, idx2 = v[j].second;
        for(auto& k: dir){
            ll x = v[j].first + k[0];
            ll y = v[j].second + k[1];
            if(x >= 0 && y >= 0 && x < n && y < n && y <= x){
                if(ans[x][y] == 0){
                    idx1 = x;
                    idx2 = y;
                    cnt++;
                }
            }
        }
        if(cnt == 1 && freq[j] > 0){
            ans[idx1][idx2] = j;
            v[j].first = idx1;
            v[j].second = idx2;
            freq[j]--;
        }
    }
  }
  for(int i = 0; i < n; i++){
    for(int j = 0; j <= i; j++){
        cout << ans[i][j] << " ";
    }
    cout << endl;
  }
}