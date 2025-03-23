#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct comp {
    bool operator()(const pair<ll, pair<ll,ll>> &a, const pair<ll, pair<ll,ll>> &b) {
        if(a.first != b.first)
            return a.first > b.first; 
        if(a.second.first != b.second.first)
            return a.second.first > b.second.first;
        return a.second.second > b.second.second;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll t; 
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        vector<ll> guest(n);
        for(auto &g : guest)
            cin >> g;
        vector<pair<ll, pair<ll,ll>>> v;
        ll cnt = 0;
        ll y = 0;
        bool done = false;
        while(!done){
            for (ll x = 0; x <= y; x++){
                if(x != y){
                    v.push_back({3LL*x + 3LL*y + 2, {3LL*x + 1, 3LL*y + 1}});
                    cnt++;
                    if(cnt >= 2 * n){ done = true; break; }
                    v.push_back({3LL*x + 3LL*y + 2, {3LL*y + 1, 3LL*x + 1}});
                    cnt++;
                    if(cnt >= 2 * n){ done = true; break; }
                }
                else{
                    v.push_back({3LL*x + 3LL*y + 2, {3LL*x + 1, 3LL*y + 1}});
                    cnt++;
                    if(cnt >= 2 * n){ done = true; break; }
                }
            }
            y++;
        }
        
        sort(v.begin(), v.end(), [](auto &a, auto &b){
            if(a.first != b.first)
                return a.first < b.first;
            if(a.second.first != b.second.first)
                return a.second.first < b.second.first;
            return a.second.second < b.second.second;
        });

        priority_queue<pair<ll, pair<ll,ll>>, vector<pair<ll, pair<ll,ll>>>, comp> pq;
        for(auto &candidate : v){
            ll d = candidate.first;
            ll x = candidate.second.first, y = candidate.second.second;
            pq.push({x + y + 1, {x + 1, y}});
            pq.push({x + y + 1, {x, y + 1}});
            pq.push({x + y + 4, {x + 1, y + 1}});
        }
    
        int idx = 0;
        for(auto g : guest){
            if(g == 0){
                cout << v[idx].second.first << " " << v[idx].second.second << "\n";
                idx++;
            }
            else { 
                ll d1 = (idx < (int)v.size() ? v[idx].first : LLONG_MAX);
                ll d2 = (!pq.empty() ? pq.top().first : LLONG_MAX);
                if(d1 < d2){
                    cout << v[idx].second.first << " " << v[idx].second.second << "\n";
                    idx++;
                }
                else if(d1 == d2){
                    ll x1 = v[idx].second.first, y1 = v[idx].second.second;
                    ll x2 = pq.top().second.first, y2 = pq.top().second.second;
                    if(x1 < x2 || (x1 == x2 && y1 <= y2)){
                        cout << x1 << " " << y1 << "\n";
                        idx++;
                    }
                    else{
                        cout << x2 << " " << y2 << "\n";
                        pq.pop();
                    }
                }
                else{
                    cout << pq.top().second.first << " " << pq.top().second.second << "\n";
                    pq.pop();
                }
            }
        }
    }
    return 0;
}