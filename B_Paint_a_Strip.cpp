#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    vector<ll> v(100001, 0);
    v[1] = 1;
    ll val = 1, i = 2;
    
    while(i <= 100000){
        val += 1;
        for(int j = i; j <= min((ll)(i)*2, (ll)100000); j++){
            v[j] = val;
        }
        i = i*2 + 1;
    }
    ll t; 
    cin >> t;
    while(t--){
        ll n; 
        cin >> n;
        if(n >= 0 && n <= 100000){
            cout << v[n] << endl;
        }
        else{
            cout << "0" << endl;
        }
    }
}