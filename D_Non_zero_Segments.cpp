#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  ll n; cin >> n; 
  vector<ll> v(n, 0); for(int i = 0; i < n; i++) cin >> v[i];
  unordered_map<ll,bool> ump;
  ll sum = 0; ll cnt = 0;
  for(int i = 0; i < n; i++){
    sum += v[i];
    if(ump[sum] || sum == 0){
        cnt++;
        ump.clear();
        sum = v[i];

    }
    ump[sum] = true;
  }
  cout << cnt << endl;
}