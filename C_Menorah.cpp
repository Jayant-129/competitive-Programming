#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    
    ll same = 0, diff = 0;
    ll cnt1s = 0, cnt0s = 0;
    ll cnt1d = 0, cnt0d = 0;
    ll A1 = 0, B1 = 0;
    
    for (int i = 0; i < n; i++){
        if(a[i]=='1') A1++;
        if(b[i]=='1') B1++;
        if(a[i] == b[i]){
            same++;
            if(a[i]=='0') cnt0s++;
            else cnt1s++;
        }
        else{
            diff++;
            if(a[i]=='0') cnt0d++;
            else cnt1d++;
        }
    }

    if(same == n){
        cout << 0 << "\n";
        return;
    }
    
    if(A1 == 0){
        cout << -1 << "\n";
        return;
    }
    
    ll ans = LLONG_MAX;
    
    if(A1 == B1){
        ans = diff;
    }
    if((n - A1 + 1) == B1){
        bool has11 = false;
        for (int i = 0; i < n; i++){
            if(a[i]=='1' && b[i]=='1'){
                has11 = true;
                break;
            }
        }
        if(has11){
            ans = min(ans, (ll)same);
        }
    
        bool has10 = false;
        for (int i = 0; i < n; i++){
            if(a[i]=='1' && b[i]=='0'){
                has10 = true;
                break;
            }
        }
        if(has10){
            ans = min(ans, (ll)(same + 2));
        }
    }
    
    if(ans == LLONG_MAX) cout << -1 << "\n";
    else cout << ans << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll t;
    cin >> t;
    while(t--){
        solve();
    }
    
    return 0;
}