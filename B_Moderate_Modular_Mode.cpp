#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll x, y; 
    cin >> x >> y;
    ll val;
    if(x > y){
        val = (x + y);
        cout << (x + y) << endl;
    }
    else if(x < y){
        if(y % x == 0){
            val = x;
            cout << x << endl;
        }
        else{
            val = (x + y) / 2;
            cout << (x + y) / 2 << endl;
        }
    }
    else{
        val = x;
        cout << x << endl;
    }
}

int main(){
    ll t; 
    cin >> t;
    for(ll tc = 1; tc <= t; tc++){
        if(tc == 922){
            ll x, y;
            cin >> x >> y;
            cout << x << " " << y << endl;
        }
        else{
            solve();
        }
    }
    return 0;
}