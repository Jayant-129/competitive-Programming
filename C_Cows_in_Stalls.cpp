#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n , k;
vector<ll> v;
bool good(ll mid){
    ll count = 1;
    for(int i = 0; i < n; i++){
        int j = i + 1;
        while(j < n && v[i] + mid > v[j]) j++;
        if(j == n) break;
        count++;
        i = j - 1;
    }
    return count >= k;
}
int main(){
  cin >> n >> k;
  v.resize(n);
  for(int i = 0; i < n; i++){
    cin >> v[i];
  }
  ll l = 0, r = 1e9;
  while(l + 1 < r){
    ll mid = l + (r - l)/2;
    if(good(mid)){
        l = mid;
    }
    else{
        r = mid;
    }
  }
  cout << l << endl;
}