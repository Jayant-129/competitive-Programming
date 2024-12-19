#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    string s;
    cin >> s;
    ll n = s.length();
    ll pos0 = s.find('0'); 

    if(pos0 == string::npos){
        cout << "1 1 1 " << n << "\n";
        return;
    }
    ll pos_end0 = pos0;
    while(pos_end0 +1 <n && s[pos_end0 +1]=='0') pos_end0++;
    ll val = pos_end0 - pos0 + 1;
    ll l1 = pos0;
    while(val > 0){
        l1--;
        val--;
    }
    if(l1 < 0) l1 = 0;
    ll r1 = n - 1 - pos0;
    cout << (l1 + 1) << " " << (l1 + 1 + r1 ) << " 1 " << n << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}