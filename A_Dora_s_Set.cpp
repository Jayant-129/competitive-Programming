#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
  ll t;
  cin >> t;
  while(t-- > 0){
    ll l ,r;
    cin >> l >> r;
    if(l%2 == 0){
        l++;
    }
    ll cnt = 0;
    for(int i = l; i <= r;  i += 4){
        if(r - i > 1){
            cnt++;
        }
    }
    cout << cnt << endl;
  }
}