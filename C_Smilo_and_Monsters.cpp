#include<bits/stdc++.h>
using namespace std;
#define ll long long


void solve(){
    ll n; cin >> n; vector<ll> v(n, 0);
    for(auto& x: v) cin >> x;
    sort(v.begin(),v.end());
    ll i = 0, j = n - 1, sum = 0;
    ll cnt = 0;
    while(i < j){
        if(sum + v[i] == v[j]){
            sum = 0;
            cnt += (v[i] + 1);
            i++;
            j--;
        }
        else if(sum  + v[i] > v[j]){
            v[i] = (v[i] - (v[j] - sum));
            cnt += (v[j] - sum + 1);
            sum = 0;
            j--;
        }
        else{
            sum += v[i];
            cnt += v[i];
            i++;
        }
        //cout << sum << " " << v[i] << " " << v[j] << " " << cnt << endl;
    }
    if(i == j){
        cnt += (min((ll)ceil((v[j] - sum)/ 2.0) + 1,v[j]));
    }
    cout << cnt << endl;
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll t; cin >> t;
    while(t--){
        solve();
    }
}