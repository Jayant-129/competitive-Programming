#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n , x; cin >> n >> x;
    ll cnt = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= (n/i); j++){
            ll mini = min((n - (i * j))/(i + j),x-i-j);
            if(mini <= 0){
                continue;
            }
            else{
                cnt += (mini);
            }
        }
    }
    cout << cnt << endl;
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  ll t; cin >> t;
  while (t--){
    solve();
  }
}