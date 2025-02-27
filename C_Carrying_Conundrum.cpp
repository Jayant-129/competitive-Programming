#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n; cin >> n;
    ll sum = 0, sum2 = 0;
    string s = to_string(n);
    for(int i = 0; i < s.size(); i++){
        if(i % 2 == 0){
            ll val = (s[i] - '0');
            sum = sum * 10 + val;
        }
        else{
            ll val = (s[i] - '0');
            sum2 = sum2 * 10 + val;
        }
    }
    //cout << sum << " " << sum2 << endl;
    sum++; sum2++;
    cout << (sum * sum2) - 2 << endl;
}

int main(){
  ll t; cin >> t;
  while(t--){
    solve();
  }
}