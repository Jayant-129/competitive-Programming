#include<bits/stdc++.h>
using namespace std;
#define ll long long
map<ll,ll> mp;
vector<pair<ll,ll>> v;

void solve(){
    ll n, k; 
    cin >> n >> k;
    
    for(ll i = 0; i < n; i++){
        ll x; 
        cin >> x;
        mp[x]++;
    }

    for(auto& i: mp){
        v.push_back({i.first,i.second});
    }

    ll sum = v[0].second; 
    ll maxi = sum;
    ll st = 0;
    for(ll i = 1; i < v.size(); i++){
        if(v[i].first == (v[i - 1].first + 1)){
            sum += v[i].second; 
        } else {
            sum = v[i].second;  
            st = i;
        }

        while((i - st + 1) > k){
            sum -= v[st].second;
            st++;
        }

        maxi = max(sum, maxi);
    }
    cout << maxi << endl;

    mp.clear();
    v.clear();
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll t; 
    cin >> t;
    while(t--){
        solve();
    }
}
