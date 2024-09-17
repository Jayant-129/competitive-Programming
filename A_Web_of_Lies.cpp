#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
  ios::sync_with_stdio(0);cin.tie(0);
  ll n , m; cin >> n >> m; vector<ll> v(n + 1,0);
  for(int i = 0; i < m; i++){
    ll x , y; cin >> x >> y; ll a = min(x,y);
    v[a]++;
  }
  set<ll> s;
  for(int i = 1; i <= n; i++){
    if(v[i] == 0){
        s.insert(i);
    }
  }
  ll q; cin >> q;
  for(int i = 0; i < q; i++){
    ll x; cin >> x;
    if(x == 1){
        ll y,z; cin >> y >> z; ll a = min(y,z); v[a]++;
        if(s.find(a) != s.end()){
            s.erase(a);
        }
        //cout << s.size() << endl;
    }
    else if(x == 2){
        ll y,z; cin >> y >> z; ll a = min(z,y); v[a]--;
        if(v[a] == 0){
            s.insert(a);
        }
        //cout << s.size() << endl;
    }
    else{
        cout << s.size() << endl;
    }
  }
}