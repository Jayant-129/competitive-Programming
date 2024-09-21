#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n , k ; cin >> n >> k;
    ll a = n - k + 1; ll r = n - (a - 1);
    ll odd = 0;
    odd = r/ 2;
    if(r % 2 != 0 && a % 2 != 0){
        odd++;
    }
    if(odd % 2 == 0){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
}

int main(){
  ll t;
  cin >> t;
  while(t-- > 0){
    solve();
  }
}