#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll n, k;
bool good(ll i) {
    ll sum_i = (i * (i + 1)) / 2;
    ll sum_n_i = ((n - 1) * n) / 2 - sum_i;
    ll val1 = k * (i + 1) + sum_i;
    ll val2 = (n - i - 1) * k + sum_n_i;
    return val1 <= val2;
}

void solve(){
    cin >> n >> k;
    ll l = 0 , r = n - 1;
    while(l + 1 < r){
        ll mid = l + (r-l)/2;
        if(good(mid)){
            l = mid;
        }
        else{
            r = mid;
        }
    }
    ll i = l;
    ll val1 = (k* (i + 1)) + ((i % 2 == 0)? i/2 * (i + 1): (i + 1)/2 * i);
    ll val2 = (n - i - 1)*k + ((n % 2 == 0)? ((n)/2*(n-1)):(n-1)/2*(n)) - ((i % 2 == 0)? i/2 * (i + 1): (i + 1)/2 * i);
    ll mini = abs(val1 - val2);
    if(l + 1 != (n - 1)){
         i = l + 1;
        ll val3 = (k* (i + 1)) + ((i % 2 == 0)? i/2 * (i + 1): (i + 1)/2 * i);
        ll val4 = (n - i - 1)*k + ((n % 2 == 0)? ((n)/2*(n-1)):(n-1)/2*(n)) - ((i % 2 == 0)? i/2 * (i + 1): (i + 1)/2 * i);
        mini = min(mini,abs(val3 - val4));
    }
    cout << mini << endl;
}

int main(){
  ios::sync_with_stdio(0);cin.tie(0);
  ll t;
  cin >> t;
  while(t-- > 0){
    solve();
  }
}