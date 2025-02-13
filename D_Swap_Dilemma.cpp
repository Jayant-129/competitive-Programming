#include<bits/stdc++.h>
using namespace std;
#define ll long long
#include <ext/pb_ds/assoc_container.hpp>  
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
void solve(){
    ll n; cin >> n;
    vector<ll> a(n + 1, 0); map<ll,bool> mp1; 
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        mp1[a[i]] = true;
    }
    vector<ll> b(n + 1, 0); 
    for(int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    map<ll,ll> mp;
    for(int i = 1; i <= n; i++){
        if(!mp1[b[i]]){
            cout << "NO" << endl;
            return;
        }
        mp[b[i]] = i;
    }
    ordered_set os; ll cnt = 0;
    for(int i = 1; i <= (n - 2); i++){
        ll idx = mp[a[i]];
        ll add = os.size() - os.order_of_key(idx);
        cnt += (idx + add  - i);
        os.insert(idx);
    }
    //cout << cnt << endl;
    if(cnt % 2){
        swap(a[n], a[n-1]);
    }
    if(mp[a[n]] > mp[a[n - 1]]){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
}

int main(){
  ll t; cin >> t;
  while(t--){
    solve();
  }
}