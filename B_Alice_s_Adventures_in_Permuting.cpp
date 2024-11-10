#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(){
    ll n, b, c;
    cin >> n >> b >> c;
    if(b == 0){
        if(c > (n - 1)){
            cout << n << endl;
        }
        else if(c == (n - 1)||  c == (n - 2)){
            cout << n - 1 << endl;
        }
        else{
            cout << -1 << endl;
        }
        return;
    }

    ll numerator = n - 1 - c;
    ll val;

    if(numerator < 0){
        val = 0;
    }
    else if(numerator < b){
        val = 1;
    }
    else{
        val = (numerator / b) + 1;
    }

    if(n <= val){
        cout << "0" << endl;
    }
    else{
        cout << (n - val) << endl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while(t--){
        solve();
    }
}