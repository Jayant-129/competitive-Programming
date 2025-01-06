#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll f(ll l,ll r){
    ll ans;
    cout << "? " << l << " " << r << endl;
    cin >> ans;
    cout.flush();
    return ans;
}

void solve(){
    ll n; cin >> n;
    string s(n + 1,'#');
    ll i = 2;
    ll prev = -1;
    while(i <= n){
        ll ans = f(1,i);
        if(ans == 0){
            i++;
            if(i == n + 1){
                cout << "! IMPOSSIBLE" << endl;
                return;
            }
            continue;
        }
        else{
            s[i] = '1';
            ll j = i - 1;
            prev = ans;
            while(ans--){
                s[j] = '0';
                j--;
            }
            i++;
            break;
        }
    }
    while(i <= n){
        ll ans = f(1,i);
        if(ans == prev){
            s[i] = '0';
        }
        else{
            s[i] = '1';
            prev = ans;
        }
        i++;
    }
    cout << "! ";
    for(int i = 1; i <= n; i++){
        if(s[i] == '#'){
            s[i] = '1';
        }
        cout << s[i];
    }
    cout << endl;
}

int main(){
  ll t; cin >> t;
  while(t--){
    solve();
  }
}