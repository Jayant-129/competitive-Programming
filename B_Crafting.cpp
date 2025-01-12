#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n; 
    cin >> n;
    vector<ll> a(n, 0); 
    for(auto& x: a) cin >> x;
    vector<ll> b(n, 0); 
    for(auto& x: b) cin >> x;
    
    // Calculate x_i = max(b[i] - a[i], 0) for each material
    vector<ll> x(n, 0);
    ll x_max = 0;
    for(int i = 0; i < n; i++){
        x[i] = max(b[i] - a[i], (ll)0);
        x_max = max(x_max, x[i]);
    }

    vector<int> candidates;
    for(int i = 0; i < n; i++){
        if(x[i] == x_max){
            candidates.push_back(i);
        }
    }
    
    bool possible = false;
    for(auto &i : candidates){
        bool valid = true;
        for(int j = 0; j < n; j++){
            if(j == i) continue;
            if(a[j] < b[j] + x_max){
                valid = false;
                break;
            }
        }
        if(valid){
            possible = true;
            break;
        }
    }
    
    cout << (possible ? "YES" : "NO") << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll t; 
    cin >> t;
    while(t--){
        solve();
    }
}