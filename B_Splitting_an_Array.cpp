#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n , k;
vector<ll> v;
bool good(ll mid){
    ll seg = 1, temp = 0;
    for(int i = 0; i < n; i++){
        if(v[i] > mid){
            return false;
        }
        if(temp + v[i] <= mid){
            temp += v[i];
        }
        else{
            seg++;
            temp = v[i];
        }
    }
    return seg <= k;
}
int main(){
  cin >> n >> k; 
  ll sum = 0;
  v.resize(n);
  for(int i = 0; i < n; i++){
    cin >> v[i];
    sum += v[i];
  }
  ll l = 0, r = sum;
  while(l + 1 < r){
    ll mid = l + (r - l)/2;
    if(good(mid)){
        r = mid;
    }
    else{
        l = mid;
    }
  }
  cout << r << endl; 
}