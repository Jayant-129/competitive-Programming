#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n,m,k; cin >> n >> m >> k;
    ll val1 = max(n,m), val2 = min(n,m);

    if(!val1 || !val2){
        if(k != val1){
            cout << -1 << endl;
            return;
        }
    }
    else{
        ll diff = abs(val1 - val2);
        if(k < diff || k > val1){
            cout << -1 << endl;
            return;
        }
    }

    char maxi, mini;
    if(n > m) maxi = '0',mini = '1';
    else maxi = '1', mini = '0';

    if(k >= val2){
        while(k--){
            cout << maxi;
            val1--;
        }
        while(val2--) cout << mini;
        while(val1--) cout << maxi;
    }
    else{
        bool flag = false;
        if(val1 == val2) flag = true;
        while(k--){
            cout << maxi;
            val1--;
        }
        while(val2 > val1){
            cout << mini;
            val2--;
        }
        while(val1-- && val2--){
            if(flag) cout << maxi << mini;
            else cout << mini << maxi;
        }
    }
    cout << endl;
}

int main(){
  ll t; cin >> t;
  while(t--){
    solve();
  }
}