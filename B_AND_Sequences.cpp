#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll M = 1e9 + 7;
vector<ll> fac(200005,1);
void solve(){
    ll n; cin >> n; vector<ll> v(n,0);
    vector<bool> v1(32,false);
    for(int i = 0; i < n; i++){
        cin >> v[i];
        for(int j = 0; j < 32; j++){
            if(!(v[i] & (1LL << j))){
                v1[j] = true;
            }
        }
    }
    ll cnt = 0;
    for(int i = 0; i < n; i++){
        bool flag = true;
        for(int j = 0; j < 32; j++){
            if(v1[j] && (v[i] & (1LL << j))){
                flag = false;
            }
        }
        if(flag){
            cnt++;
        }
    }
    if(cnt == 0){
        cout << 0 << endl;
    }
    else{
        cnt = cnt % M;
        ll ans1 = (cnt * (cnt - 1)) % M;
        ll ans = ((ans1) * (fac[n - 2])) % M;
        cout << ans << endl;
    }
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  for(int i = 1; i < 200005; i++){
    fac[i] = ((i % M) * fac[i - 1]) % M;
  }
  ll t;
  cin >> t;
  while(t-- > 0){
    solve();
  }
}