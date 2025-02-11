#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n; cin >> n;
    ll prev = n % 10, mini,i = 1; n /= 10; 
    if(prev <= 7){
        mini = prev + 2;
    }
    else{
        mini = 7 - prev;
    }
    while(n > 0){
        ll curr = n % 10;
        n /= 10;
        ll cnt = 10;
        if(curr <= 7){
            
        }
        else(curr > 7){
            cnt = min(cnt,min(17 - curr,));
        }
        prev = curr * pow(10,i) + prev; i++;
        mini = min(cnt,mini);
    }
    cout << mini << endl;
}

int main(){
  ll t; cin >> t;
  while(t--){
    solve();
  }
}