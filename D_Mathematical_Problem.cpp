#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n; 
    cin >> n;
    string s; 
    cin >> s;
    if(n == 2){
        cout << stoi(s) << endl;
        return;
    }
    vector<ll> pre(n, 0);
    ll idx = -1;
    for(int i = 0; i < n; i++){
        if(s[i] == '0'){
            idx = i;
        }
    }
    if(idx == 0 || idx == n - 1){
        cout << 0 << endl;
        return;
    }
    if(idx != -1 && n > 3){
        cout << 0 << endl;
        return;
    }
    pre[0] = s[0] - '0';
    for(int i = 1; i < n; i++){
        ll val1 = pre[i - 1];
        ll val2 = s[i] - '0';
        if(val1 == 1 || val2 == 1){
            pre[i] = pre[i - 1] * val2;
        }
        else{
            pre[i] = pre[i - 1] + val2;
        }
    }
    vector<ll> suf(n, 0);
    suf[n - 1] = s[n - 1] - '0';
    for(int i = n - 2; i >= 0; i--){
        ll val1 = suf[i + 1];
        ll val2 = s[i] - '0';
        if(val1 == 1 || val2 == 1){
            suf[i] = suf[i + 1] * (s[i] - '0');
        }
        else{
            suf[i] = suf[i + 1] + val2;
        }
    }

    ll mini = LLONG_MAX;
    for(int i = 0; i < (n - 1); i++){
        ll val1 = 0, val2 = 0;
        if(i) val1 = pre[i - 1];
        if(i + 2 < n) val2 = suf[i + 2];
        ll val3 = stoi(s.substr(i, 2));
        if(i == 0){
            mini = min(mini, min(val2 + val3,val2 * val3));
        }
        else if(i == n - 2){
            mini = min(mini, min(val1 * val3 ,val1 + val3));
        }
        else{
             ll a = val1 + val2 + val3;
            ll b = val1 + val2 * val3;
            ll c = val1 * val3 + val2;
            ll d = val1 * val2 * val3;
            mini = min(mini,min(a,min(b,min(c,d))));
        }
    }
    cout << mini << endl;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll t;
    cin >> t;
    while(t-- > 0){
        solve();
    }
    return 0;
}
