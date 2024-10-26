#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll M = 998244353;
ll binExpMod(ll base, ll exp, ll mod) {
    ll result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1) { 
            result = (result * base) % mod;
        }
        exp = exp >> 1; 
        base = (base * base) % mod;
    }
    return result;
}
int main(){
  ll n; cin >> n;
  vector<ll> v(n + 1);
  vector<ll> m;
  for(int i = 1; i <= n; i++) cin >> v[i];
  for(int i = 1; i <= n; i++){
    ll maxi = INT_MIN;
    for(int j = i; j <= n; j += i){
        maxi = max(maxi, v[j]);
    }
    m.push_back(maxi);
  }
  sort(m.begin(),m.end(),greater<ll>());
  ll ans = 0;
  for(int i = 0; i < n; i++){
    ans = (ans + (m[i] * (binExpMod(2,(n - i - 1),M))) % M) % M;
  }
  cout << ans << endl;
}