#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    multimap<ll,ll> mp , mp1;
    ll q; cin >> q;
    ll k = 1;
    for(int i = 0; i < q; i++){
        ll x; cin >> x;
        if(x == 1){
             ll y; 
            cin >> y;
            mp.insert({k, y});   
            mp1.insert({y, k});
            k++;
        }
        else if(x == 2){
            auto it = mp.begin();
            ll val = it->second;
            cout << it->first << " ";
            mp1.erase(val);
            mp.erase(it->first);
        }
        else{
            auto it = mp1.rbegin();
            ll val = it->first; 
            auto range = mp1.equal_range(val);
            auto fo = range.first;
            cout << fo->second << " ";
            mp.erase(fo->second);
            mp1.erase(fo); 
        }
        // cout << "debug" << endl;
        // for(auto& i: mp1){
        //     cout << i.first << " " << i.second << endl;
        // }
        // for(auto& i: mp){
        //     cout << i.first << " " << i.second << endl;
        // }
        // cout << "end" << endl;
    }
    cout << endl;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    solve();
}