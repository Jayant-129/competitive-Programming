#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    ll n, k;
    cin >> n >> k;
    vector<ll> v(n,0);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    vector<ll> v1(k,0);
    ll cnt = 0;
    for(auto& i: v){
        v1[i % k]++;
        cnt += (i / k);
    }
    ll st = 1;
    ll e = k - 1;
    while(st < e){
        cnt += (min(v1[st],v1[e]));
        if(v1[st] < v1[e]){
            v1[e] -= v1[st]; 
            v1[st] = 0;
        }
        else{
            v1[st] -= v1[e];
            v1[e] = 0;
        }
        st++;
        e--;
    }
    if(st == e){
        cnt += (v1[st]/2);
        if(v1[st] % 2 == 0){
            v1[st] = 0;
        }
        else{
            v1[st] = 1;
        }
    }
    st = 1;
    e = k - 1;
    while(st < e){
        ll val = st + e;
        if(val < k){
            st++;
        }
        else if(val >= k){
            cnt += (min(v1[st],v1[e]));
            if(v1[st] < v1[e]){
                v1[e] -= v1[st]; 
                v1[st] = 0;
                st++;
            }
            else{
                v1[st] -= v1[e];
                v1[e] = 0;
                e--;
            }
        }
    }
    if(st == e && (st + e) >= k){
        cnt += (v1[st]/2);
    }
    cout << cnt << endl;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    ll t;
    cin >> t;
    while(t--){
        solve();
    }
}