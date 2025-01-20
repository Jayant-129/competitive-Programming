#include<bits/stdc++.h>
using namespace std;
#define ll long long

void f(ll i, vector<ll>& a, vector<ll>& b){
    stack<ll> s;
    ll n = a.size();
    for(int j = n - 1; j >= i; j--){
        s.push(a.back());
        a.pop_back();
    }
    while(!s.empty()){
        b.push_back(s.top());
        s.pop();
    }
}
void solve(){
    ll n, q; cin >> n >> q;
    vector<ll> a,b;
    b.push_back(2);
    for(int i = 1; i<= n; i++) a.push_back(i);
    for(int i = 1; i < n; i++){
        cout << i << " " << i + 1 << endl;
    }
    ll d = n - 1;
    for(int i = 0; i < q; i++){
        ll x; cin >> x;
        if(d < x){
            ll req = x - d;
            ll z = b.size() - 1;
            cout << b[z - req + 1] << " " << b[z - req] << " " << a[d] << endl;
            f(z - req + 1, b , a);
        }
        else if(d > x){
            cout << a[x + 1] << " " << a[x] << " " << b.back() << endl;
            f(x + 1,a,b);
        }
        else{
            cout << -1 << " " << -1 << " " << -1 << endl;
        }
        d = x;
    }
}
int main(){
  ll t; cin >> t;
  while(t--){
    solve();
  }
}