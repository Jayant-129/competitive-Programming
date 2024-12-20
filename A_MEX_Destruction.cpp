#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(auto &x : a) cin >> x;

    bool all_zero = true;
    for(auto x : a){
        if(x != 0){
            all_zero = false;
            break;
        }
    }
    if(all_zero){
        cout << "0\n";
        return;
    }
    int count = 0;
    bool in_segment = false;
    for(auto x : a){
        if(x != 0){
            if(!in_segment){
                count++;
                in_segment = true;
            }
        }
        else{
            in_segment = false;
        }
    }
    if(count == 1){
        cout << "1\n";
    }
    else{
        cout << "2\n";
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