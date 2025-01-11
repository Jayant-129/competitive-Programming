#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll> dp;
bool rec(int n, int x, int y){
    if()
}
void solve(){
    ll n , x, y;
    cin >> n >> x >> y;
    bool flag = rec(n,x,y);
    if(flag){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
}

int main(){
  dp.resize(45,1);
  for(int i = 2; i <= 44; i++){
    dp[i] = dp[i - 1] + dp[i - 2];
  }
  ll t; cin >> t;
  while(t--){
    solve();
  }
}