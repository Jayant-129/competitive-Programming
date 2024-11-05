#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll> v;
vector<ll> pre;
void solve(){
    ll n; cin >> n;
    pre.resize(n + 1,0);v.resize(n,0); for(auto& x: v) cin >> x;
    string s; cin >> s;
    ll cnt1 = 0, cnt0 = 0;
    pre[0] = 0;
    for(int i = 1; i <= n; i++){
        pre[i] = v[i];
        if(i) pre[i] = pre[i] ^ pre[i - 1];
    }
    for(int i = 0; i < s.length(); i++){
        if(s[i] == '0'){
            cnt0 = cnt0 ^ v[i];
        }
        else{
            cnt1 = cnt1 ^ v[i];
        }
    }
    ll q; cin >> q;
    for(int i = 0; i < q; i++){
        int a; cin >> a;
        if(a == 1){
            ll l, r , val; cin >> l >> r;
            val = pre[r] ^ pre[l - 1];
            cnt1 = cnt1 ^ val;
            cnt0 = cnt0 ^ val;
        }
        else{
            ll b; cin >> b;
            if(b == 1){
                cout << cnt1 << " ";
            }
            else{
                cout << cnt0 << " ";
            }
        }
    }
    cout << endl;
    v.clear();
    pre.clear();
}

int main(){
  ll t; cin >> t;
  while(t--){
    solve();
  }
}