#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
  ll t;
  cin >> t;
  set<ll> s;
  for(int k = 2; k <= 1000; k++){
    ll val = k + 1;
    for(int i = 2; i <= 20; i++){
        ll p = (ll)pow(k, i);
        if(p + val > 1000000){
            break;
        }
        val += p;
        s.insert(val);
    }
  }
  while(t-- > 0){
    ll n;
    cin >> n;
    if(s.find(n) != s.end()){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
  }
}