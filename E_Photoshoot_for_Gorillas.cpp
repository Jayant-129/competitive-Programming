#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n , m ,k ;cin >> n >> m >> k;
    vector<ll> v;
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < m; j++){
            ll sc = max(0LL,j - k + 1);
            ll ec = min(j,m - k);
            ll sr = max(0LL,i - k + 1);
            ll er = min(i,n- k);
            v.push_back((ec - sc  + 1) * (er - sr + 1));
        }
    }
    sort(v.begin(),v.end(),greater<ll>());
    ll num; cin >> num;vector<ll> v1(num,0);
    for(ll i = 0; i < num; i++){
        cin >> v1[i];
    }
    sort(v1.begin(),v1.end(),greater<ll>());ll sum  = 0;
    for(ll i = 0; i < num; i++){
        sum += (v[i] * v1[i]);
    }
    cout << sum << endl;
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  ll t;
  cin >> t;
  while(t-- > 0){
    solve();
  }
}