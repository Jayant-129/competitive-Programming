#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    
}
int main(){
  ll n; cin >> n;
  vector<ll> v(n, 0);
  for(int i = 0; i < n; i++) cin >> v[i];
  sort(v.begin(),v.end());
  vector<ll> a(n,0);
  ll j = n/2;ll k = 0;
  for(int i = 0; i < n; i++){
    if(i % 2){
        a[i] = v[k];
        k++;
    }
    else{
        a[i] = v[j];
        j++;
    }
  }
  ll cnt = 0;
  for(int i = 1; i < n; i += 2){
    if((a[i - 1] > a[i]) && (i != n - 1 && a[i + 1] > a[i])){
        cnt++;
    }
  }
  cout << cnt << endl;
  for(auto& x: a) cout << x << " "; cout << endl;
}