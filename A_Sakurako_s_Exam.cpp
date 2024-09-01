#include<bits/stdc++.h>
using namespace std;
#define ll long long


void solve(){
    ll a, b;
    cin >> a >> b;
    b = b%2;
    if(b == 0){
        if(a % 2 == 0){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    else{
        if(a % 2 == 0 && a > 0){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }

}

int main(){
  ll t;
  cin >> t;
  while(t-- > 0){
    solve();
  }
}