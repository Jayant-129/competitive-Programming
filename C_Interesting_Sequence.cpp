#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long

void solve(){
    ll n, x; cin >> n >> x;
    if(n == x){
        cout << n << endl;
        return;
    }
    for(ll i = 0; i <= 63; i++){
        if((1LL << i) & n){
            n = n ^ (1LL << i);
        }
        if(n == x){
            ll j = i + 1;
            if(n & (1LL << j)){
                cout << -1 << endl;
            }
            else{
                n = n | (1LL << j);
                cout << n << endl;
            }
            return;
        }
    }
    cout << -1 << endl;
}

int main(){
    ll t; cin >> t;
    while(t--){
        solve();
    }
}