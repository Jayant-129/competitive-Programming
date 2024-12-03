#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n; 
    cin >> n;
    vector<pair<ll, ll>> v(n, {0, 0});
    
    for(int i = 0; i < n; i++){
        cin >> v[i].first;
    }
    
    for(int i = 0; i < n; i++){
        ll x; 
        cin >> x;
        v[i].second = x;
    }
    
    ll ans = 0;
    ll idx = -1, maxi = INT_MIN, maxi2 = INT_MIN;
    for(int i = 0; i < n; i++){
        if(v[i].first > v[i].second){
            ans += v[i].first;
            maxi = max(maxi, v[i].second);
        }
        else{
            ans += v[i].second;
            maxi2 = max(maxi2, v[i].first);
        }
    }
    cout << ans + (max(maxi,maxi2)) << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); 
    ll t; 
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}