#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 200001
bool c[N];
void doit(vector<ll>& v){
    for(ll i = 0; i <= (v.size()); i++){
        c[i] = false;
    }
    ll maxi = 0;
    for(ll i = 0; i < v.size(); i++){
        if(c[v[i]]){
            maxi = max(maxi,v[i]);
        }
        c[v[i]] = true;
        v[i] = maxi;
    }
}

void solve(){
    ll n;
    cin >> n;
    vector<ll> v(n,0);
    ll ans = 0;
    for(ll i = 0; i < n; i++){
        cin >> v[i];
        ans += v[i];
    }
    doit(v);
    for(ll i = 0; i < n; i++){
        ans += v[i];
    }
    doit(v);
    for(ll i = 0; i < n; i++){
        ans += ((n - i) * v[i]);
    }
    cout << ans << endl;
}

int main(){
 ios::sync_with_stdio(0); cin.tie(0);
  ll t;
  cin >> t;
  while(t-- > 0){
    solve();
  }
}