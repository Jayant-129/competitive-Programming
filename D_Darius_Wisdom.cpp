#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n; 
    cin >> n;
    vector<ll> v(n);
    set<ll> z, o, t;
    for(int i = 0; i < n; i++){
        cin >> v[i];
        if(v[i] == 0){
            z.insert(i);
        }
        else if(v[i] == 1){
            o.insert(i);
        }
        else{
            t.insert(i);
        }
    }
    vector<pair<int, int>> moves;
    ll cnt0 = z.size();
    for(int i = 0; i < cnt0; i++){
        if(v[i] == 0){
            z.erase(i);
            continue;
        }
        else if(v[i] == 1){
            ll val = *z.begin();
            swap(v[i], v[val]);
            moves.emplace_back(val + 1, i + 1);
            z.erase(val);
            o.erase(i);
            o.insert(val);
        }
        else{
            ll one = *o.begin();
            swap(v[i], v[one]);
            moves.emplace_back(one + 1, i + 1);
            o.erase(one);
            t.erase(i);
            t.insert(one);
            
            ll val = *z.begin();
            swap(v[i], v[val]);
            moves.emplace_back(val + 1, i + 1);
            z.erase(val);
            t.erase(one);
            o.insert(val);
        }
    }
    ll cnt1 = o.size();
    for(int i = cnt0; i < cnt0 + cnt1; i++){
        if(v[i] == 1){
            o.erase(i);
            continue;
        }
        else{
            ll val = *o.begin();
            swap(v[i], v[val]);
            moves.emplace_back(val + 1, i + 1);
            o.erase(val);
            t.erase(i);
            t.insert(val);
        }
    }
    if(moves.size() > n){
        cout << "0\n";
        return;
    }
    bool sorted_flag = true;
    for(int i =1; i < n; ++i){
        if(v[i] < v[i-1]){
            sorted_flag = false;
            break;
        }
    }
    if(sorted_flag){
        cout << moves.size() << "\n";
        for(auto &[u, v_] : moves){
            cout << u << " " << v_ << "\n";
        }
    }
    else{
        cout << "0\n";
    }
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