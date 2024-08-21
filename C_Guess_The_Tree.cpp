#include<bits/stdc++.h>
using namespace std;
#define ll long long

int query(int a, int b){
    cout << "?" << " " << a << " " << b << endl;
    cout.flush();
    int r;
    cin >> r;
    return r - 1;
}

void solve(){
    int n; cin >> n;
    vector<int> out(n,0);
    for (int i = 0; i < n; i++)
    {
        out.push_back(i);
    }
    vector<pair<int,int>> p;
    vector<bool> vis(n, false);
    vis[0] = true;
    while(!out.empty()){
        ll x = out[out.size() - 1];
        out.pop_back();
        if(vis[x]) continue;
        int s = 0 , e = x;
        while(true){
            int r = query(s + 1,e + 1);
            if(s == r){
                vis[e] = true;
                p.push_back({s,e});
                break;
            }
            if(vis[r]){
                s = r;
            }
            else{ 
                e = r;
            }
        }
        out.push_back(x);
    }
    cout << "!" << " ";
    for(auto& [x,y]:p){
        cout << x + 1 << " " << y + 1 << " ";
    }
    cout << endl;
}
int main(){
    ll t;
    cin >> t;
    while(t-- > 0){
        solve();
    }
}