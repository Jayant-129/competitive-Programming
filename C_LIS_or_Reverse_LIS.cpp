#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n;
    cin >> n;
    unordered_map<ll,ll> ump;
    ump.reserve(1024);
    ump.max_load_factor(0.25);
    vector<ll> v;
    for(ll i = 0; i < n; i++){
        ll x;
        cin >> x;
        ump[x]++;
        if(ump[x] <= 2){
            v.push_back(x);
        }
    }
    ll s = v.size();
    if(s % 2 == 0){
        cout << s/2 << endl;
    }
    else{
        cout << s/2 + 1 << endl;
    }
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    ll t;
    cin >> t;
    while(t-- > 0){
        solve();
    }
}