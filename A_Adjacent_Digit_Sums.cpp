#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll x, y;
    cin >> x >> y;
    if(y == x + 1){
        cout << "YES" << "\n";
        return;
    }
    if(x + 1 > y && (x + 1 - y) % 9 == 0)
        cout << "YES" << "\n";
    else
        cout << "NO" << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll t; 
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}