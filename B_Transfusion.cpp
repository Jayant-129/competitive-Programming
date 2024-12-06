#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    ll n; cin >> n;
    ll sum = 0, sum2 = 0, cnt1 = 0, cnt2 = 0;
    for(int i = 0; i < n; i++){
        ll x; cin >> x;
        if(i % 2){
            sum += x;
            cnt1++;
        }
        else{
            sum2 += x;
            cnt2++;
        }
    }
    if(sum/cnt1 == sum2/cnt2 && sum % cnt1 == 0 && sum2 % cnt2 == 0){
        cout << "YES" << endl;
    }
    else{
         cout << "NO" << endl;
    }
}
int main(){
  ll t; cin >> t;
  while(t--){
    solve();
  }
}