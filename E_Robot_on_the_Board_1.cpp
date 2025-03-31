#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
void solve(){
    ll n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    ll x = 0, y = 0;
    ll minx = 0, maxx = 0, miny = 0, maxy = 0;
    pair<ll,ll> best = {1, 1};
 
    for (char c : s) {
        if(c=='L'){
            y--;
        }
        else if(c=='R'){
            y++;
        }
        else if(c=='U'){
            x--;
        }
        else if(c=='D'){
            x++;
        }
        minx = min(minx, x);
        maxx = max(maxx, x);
        miny = min(miny, y);
        maxy = max(maxy, y);

        if(maxx - minx < n && maxy - miny < m){
            best = {1 - minx, 1 - miny};
        }
        else{
            break;
        }
    }
    
    cout << best.first << " " << best.second << "\n";
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    
    return 0;
}
