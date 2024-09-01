#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n , a, b;
    cin >> n >> a >> b;
    ll g = __gcd(a,b);
    set<ll> s;
    for(ll i = 0;i < n; i++){
        ll x;
        cin >> x;
        s.insert(x % g);
    }
    n = s.size();
    ll mini = INT_MAX;
    for(ll i = 0; i < (n - 1); i++){
        ll st = *s.begin();
        auto end = *(--s.end());
        mini = min(abs(st-end),mini);
        //cout << end <<  " " << st << " " << endl;
        s.erase(*s.begin());
        s.insert(st + g);
        st = *s.begin();
        end = *(--s.end());
        mini = min(abs(st-end),mini);
        //cout << end <<  " " << st << " " << endl;
    }
    if(mini == INT_MAX){
        //cout << s.size() << endl;
        cout << 0 << endl;
        return;
    }
    cout << mini << endl;
}

int main(){
  ll t;
  cin >> t;
  while(t-- > 0){
    solve();
  }
}