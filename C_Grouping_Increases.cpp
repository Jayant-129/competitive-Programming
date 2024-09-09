#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n;
    cin >> n;
    vector<ll> v(n,0);
    for(int i= 0; i < n; i++){
        cin >> v[i];
    }
    ll x = INT_MAX , y = INT_MAX,cnt = 0;
    for(int i = 0; i < n; i++){
        if(x <= y){
            if(v[i] <= x){
                x = v[i];
            }
            else if(y < v[i]){
                cnt++;
                x = v[i];
            }
            else{
                y = v[i];
            }
        }
        else{
            if(v[i] <= y){
                y = v[i];
            }
            else if(x < v[i]){
                cnt++;
                y = v[i];
            }
            else{
                x = v[i];
            }
        }
    }
    cout << cnt << endl;
}

int main(){
  ios::sync_with_stdio(0);cin.tie(0);
  ll t;
  cin >> t;
  while(t-- > 0){
    solve();
  }
}