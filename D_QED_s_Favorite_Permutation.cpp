#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll> pre;
ll cnt = 0;
string s;
void f(ll i, bool flag){
    if(s[i] == 'L' && s[i + 1] == 'R' && pre[i] > i){
        if(flag) cnt++;
        else cnt--;
    }
}
void solve(){
    ll n , q; cin  >> n >> q;
    vector<ll> v(n + 1, 0);for(int i = 1;i <= n; i++) cin >> v[i];
    cin >> s;  s = '#' + s;
    pre.resize(n + 1,0);
    for(int i = 1; i <= n; i++){
       pre[i] = max(pre[i - 1],v[i]);
    }
    for(int i = 2; i < n; i++){
        f(i,1);
    }
    for(int i = 0; i < q; i++){
        ll x; cin >> x;
        f(x,0);
        f(x-1,0);
        if(s[x] == 'L'){
            s[x] = 'R';
        }
        else{
            s[x] = 'L';
        }
        f(x,1);
        f(x-1,1);
        if(cnt > 0) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
    pre.clear();
    cnt = 0;
    s.clear();
}
int main(){
  ll t; cin >> t;
  while(t--){
    solve();
  }
}