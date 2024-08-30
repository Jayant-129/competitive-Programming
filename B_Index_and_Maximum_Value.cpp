#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    ll n, m;
    cin >> n >> m;
    vector<ll> v(n,0);
    ll maxi = 0;
    for(int i = 0 ; i < n; i++){
        cin >> v[i];
        maxi = max(maxi, v[i]);
    }
    vector<ll> ans;
    for(int i = 0; i < m; i++){
        char sign; ll l , r;
        cin >> sign >> l >> r;
        if(maxi >= l && maxi <= r){
            if(sign == '+'){
                maxi++;
            }
            else{
                maxi--;
            }
        }
        ans.push_back(maxi);
    }
    for(auto& i: ans){
        cout << i << " ";
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