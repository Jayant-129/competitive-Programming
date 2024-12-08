#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll> v;
void rec(ll i, ll j,ll k, ll n, ll m){
    if(i == j){
        v[i] = m;
        return;
    }
    ll val;
    if(n <= 60){
        val = pow(2,n - 2);
    }
    else{
        val = LLONG_MAX;
    }
    if(k <= val){
        v[i] = m;
        rec(i + 1,j,k, n - 1, m + 1);
    }
    else{
        v[j] = m;
        rec(i,j - 1,k - val, n - 1,m + 1);
    }
}
void solve(){
    ll n , k; cin >> n >> k;
    if(n <= 50 && (1LL << (n - 1)) < k){
        cout << -1 << endl;
        return;
    }
    v.resize(n,-1);
    rec(0,n - 1, k, n , 1);
    for(ll i = 0; i < n; i++){
        cout << v[i] << " ";
    }
    cout << endl;
    v.clear();
}
int main(){
  ll t; cin >> t;
  while(t--){
    solve();
  }
}