#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool vis[200010];
void solve(){
    ll n , m;
    cin >> n >> m;
    ll k = INT_MIN;
    for(ll i = 0; i < n; i++){
        ll x;
        cin >> x;
        for(ll j = 0; j < (x + 5); j++){
            vis[j] = 0;
        }
        for(ll j = 0; j < x; j++){
            ll y;
            cin >> y;
            if(y < (x + 5)){
                vis[y] = 1;
            }
        }
        ll cnt = 0;
        for(ll j = 0; j < (x + 5); j++){
            if(!vis[j]){
                cnt++;
                if(cnt == 2){
                    k = max(k,j);
                    break;
                }
            }
        }
    }
    if(m <= k){
        cout << (m + 1) * k << endl;
    }
    else{
        ll sum1 = (m * (m + 1))/2;
        ll sum2 = (k * (k + 1))/2;
        ll ans = (sum1 - sum2) + ((k + 1)*k);
        cout << ans << endl;
    }
}


int main(){
 ios::sync_with_stdio(0); cin.tie(0);
  ll t;
  cin >> t;
  while(t-- > 0){
    solve();
  }
}