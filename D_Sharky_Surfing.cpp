#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n, m, l; 
    cin >> n >> m >> l;

    vector<pair<ll, ll>> v;
    for(int i = 0; i < n; i++){
        ll x, y; 
        cin >> x >> y;
        v.push_back({x, y});
    }

    vector<pair<ll, ll>> v1;
    for(int i = 0; i < m; i++){
        ll x, y; 
        cin >> x >> y;
        v1.push_back({x, y});
    }

    ll j = 0;
    priority_queue<ll> pq;
    ll k = 1;
    ll cnt = 0;

    for(int i = 0; i < n; i++){
        auto p1 = v[i];
        
        while(j < m && v1[j].first < p1.first){
            //cout << v1[j].first << " " << v1[j].second  << endl;
            pq.push(v1[j].second);
            j++;
        }

        ll val =  (p1.second - p1.first + 2);
        
        while(k < val){
            if(pq.empty()){
                cout << -1 << endl;
                return;
            }
            auto it = pq.top(); 
            pq.pop();
            k += it;
            cnt++;
        }
    }
    cout << cnt << endl;
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