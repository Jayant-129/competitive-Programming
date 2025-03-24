#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n, k; 
    cin >> n >> k;
    vector<ll> v;
    for(int i = 31; i >= 0; i--){
        if(n & (1LL << i)){
            v.push_back((ll)pow(2,i));
        }
    }

    if(v.size() == 1){
        for(ll i = 0; i < n; i++){
            cout << k << " ";
        }
        cout << "\n";
    }
    else{
        ll val = v[1];
        for(size_t i = 2; i < v.size(); i++){
            val -= v[i];
        }
        ll num = v[v.size() - 1];
        bool flag = true;
        ll printed = 0;
        while(printed < n){
            if(flag){
                for(int j = 1; j <= num && printed < n; j++){
                    cout << k << " ";
                    printed++;
                }
                flag = false;
            }
            else{
                for(int j = 1; j <= val && printed < n; j++){
                    cout << 0 << " ";
                    printed++;
                }
                flag = true;
            }
        }
        cout << "\n";
    }
}

int main(){
    ll t; 
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}