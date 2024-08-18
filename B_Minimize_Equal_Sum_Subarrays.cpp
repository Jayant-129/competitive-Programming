#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n;
    cin >> n;
    vector<ll> v(n, 0);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    ll temp  = v[n - 1];
    for(int i = n - 1; i > 0; i--){
        v[i] = v[i - 1];
    }
    v[0] = temp;
    for(int i = 0; i < n; i++){
        cout << v[i] << " ";
    }
    cout << endl;
}

int main(){
    ll t;
    cin >> t;
    while(t-- > 0){
        solve();
    }
}