#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n; cin >> n;
    vector<ll> v(n + 1, 0); for(int i = 1;i <= n; i++) cin >> v[i];
    vector<ll> pre(n + 1,0); map<ll,ll> even; even[0] = 0;map<ll,ll> odd;
    for(int i = 0; i <= n; i++){
        pre[i] = v[i];
        if(i) pre[i] = pre[i] ^ pre[i - 1];
    }  
    ll ans = 0;
    for(int i = 1; i <= n; i++){
        ll val;
        if(i % 2){
            if(odd.find(pre[i]) == odd.end()){
                val = 0;
                odd[pre[i]] = 0;
            }
            else{
                  val = odd[pre[i]] + 1;
                  odd[pre[i]] = val;
            }
        }
        else{
            if(even.find(pre[i]) == even.end()){
                val = 0;
                even[pre[i]] = 0;
            }
            else{
                val = even[pre[i]] + 1;
                even[pre[i]] = val;
            }
        }
        ans += val;
    }
    cout << ans << endl;
}

int main(){
    solve();
}