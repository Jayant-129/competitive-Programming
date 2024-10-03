#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll> v;

void solve(){
    ll n , a , b, c, e;
    cin >> n >> a >> b >> c >> e;
    for(auto& i: v){
        ll u , r, d , l; u=a;r=b;d = c;l=e;
        for(int j = 0; j < 4; j++){
            if(j == 0 && (i & (1LL << j))){
                r--;
                d--;
            }
            else if(j == 1 && (i & (1LL << j))){
                l--;
                d--;
            }
            else if(j == 2 && (i & (1LL << j))){
                u--;
                r--;
            }
            else if(j == 3 && (i & (1LL << j))){
                u--;
                l--;
            }
        }
        if(u >= 0 && u < n - 1 && r < n - 1 && d < n - 1 && l < n - 1 && r >= 0 && d >= 0 && l >= 0){
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
}
int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  for(int i = 0; i < 16; i++){
    v.push_back(i);
  }
  ll t;
  cin >> t;
  while(t-- > 0){
    solve();
  }
}