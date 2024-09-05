#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    ll n;
    cin >> n;
    vector<ll> v(n,0);
    bool f1 = false , f2 = false;
    for(int i = 0; i < n; i++){
        ll x;
        cin >> x;
        if(x&1){f1 = true;}
        else{ f2 = true;}
    }
    if(f1 && f2){
        cout << -1 << endl;
        return;
    }
    vector<ll> ans;
    for(int i = 29; i >= 0; i--){
        ans.push_back(1 << i);
    }
    if(f2){
        ans.push_back(1);
    }
    cout << ans.size() << endl;
    for(auto& i: ans){
        cout << i << " ";
    }
    cout << endl;
}

int main(){
    ll t;
    cin >> t;
    while(t--){
        solve();
    }
}