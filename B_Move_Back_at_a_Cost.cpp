#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n; 
    cin >> n; 
    vector<ll> v2(n, 0);
    multiset<ll> mp;
    for(int i = 0; i < n; i++){
        cin >> v2[i];
        mp.insert(v2[i]);
    }
    ll k = -1;
    vector<ll> ans, ans2;
    for(int i = 0; i < n; i++){
        auto it = mp.lower_bound(k);
        if(it == mp.end()){
            break;
        }
        ll val = *it;
        if(v2[i] == val){
            auto erase_it = mp.find(val);
            if(erase_it != mp.end()){
                mp.erase(erase_it);
            }
            ans.push_back(v2[i]);
            k = val;
        }
        else{
            auto erase_it = mp.find(v2[i]);
            if(erase_it != mp.end()){
                mp.erase(erase_it);
            }
            ans2.push_back(v2[i] + 1);
            mp.insert(v2[i] + 1);
            k = val;
        }
    }
    sort(ans2.begin(), ans2.end());
    for(auto num : ans){
        cout << num << " ";
    }
    for(auto num : ans2){
        cout << num << " ";
    }
    cout << endl;
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