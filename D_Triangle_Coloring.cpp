#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 998244353;
ll modExp(ll base, ll exp, ll mod = MOD) {
    ll result = 1;
    base %= mod;
    while(exp > 0) {
        if(exp & 1)
            result = (result * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return result;
}

vector<ll> fact, invFact;

void precomputeFactorials(ll n) {
    fact.resize(n + 1);
    invFact.resize(n + 1);
    fact[0] = 1;
    for (ll i = 1; i <= n; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    invFact[n] = modExp(fact[n], MOD - 2, MOD); 
    for (ll i = n; i >= 1; i--) {
        invFact[i - 1] = (invFact[i] * i) % MOD;
    }
}

ll combination(ll n, ll r) {
    if (r < 0 || r > n) return 0;
    return ((fact[n] * invFact[r]) % MOD * invFact[n - r]) % MOD;
}

ll nCn2(ll n) {
    ll r = n / 2;
    return combination(n, r);
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n; cin >> n;
  vector<ll> v(n, 0); for(auto& x: v) cin >> x;
  precomputeFactorials(n);
  vector<ll> ans;
  for(int i = 0; i < n; i += 3){
    ll mini = 10001, cnt = 0;
    for(int j = i; j < i + 3; j++){
        mini = min(mini,v[j]);
    }
    for(int j = i; j < i + 3; j++){
        if(v[j] == mini){
            cnt++;
        }
    }
    ans.push_back(cnt);
  }

  ll val  = nCn2(ans.size());
  for(auto& i: ans){
    val = (val * i)%MOD;
  }
  cout << val << endl;
}