#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    ll n , x , y; cin >> n >> x >> y;
    ll mini = min(x,y);
    if(n % mini == 0){
        cout <<  n / mini << endl;
    }
    else{
        cout << n/mini + 1 << endl;
    }
}

int main(){
  ll t;
  cin >> t;
  while(t-- > 0){
    solve();
  }
}