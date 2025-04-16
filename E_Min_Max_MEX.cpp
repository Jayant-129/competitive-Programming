#include<bits/stdc++.h>
using namespace std;
#define ll long long

bool good(ll mid, ll k,vector<ll>& v){
    ll cnt = 0, n = v.size();
    vector<ll> mex(n + 1,0);
    for(int i = 0; i < n; i++){
        ll j = 0;
        while(i < n && j < mid){
            if(v[i] < n) mex[v[i]] = (cnt + 1);
            while(mex[j] == (cnt + 1)) j++;
            i++;
        }
        i--;
        if(j >= mid) cnt++;
    }
    return cnt >= k;
}

void solve(){
    ll n ,k; cin >> n >> k;
    vector<ll> v(n, 0);
    vector<ll> mex(n + 1,0);
    for(int i = 0; i < n; i++){
        cin >> v[i];
        if(v[i] < n) mex[v[i]]++;
    }

    ll l = 0, r = -1, i = 0;
    while(true){
        if(mex[i] == 0){
            r = i + 1;
            break;
        }
        i++;
    }
    //cout << l << " " << r << endl;
    while(l + 1 < r){
        ll mid = l + (r - l)/2;
        //cout << mid << " " << good(mid,k,v) << endl;
        if(good(mid,k,v)){
            l = mid;
        }
        else{
            r = mid;
        }
    }
    cout << l << endl;
}

int main(){
  ll t; cin >> t;
  while(t--){
    solve();
  }
}