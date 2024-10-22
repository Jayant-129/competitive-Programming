#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n , k , m; cin >> n >> k >> m; string s; cin >> s;
    string ans = "";
    vector<bool> v(26,false);
    for(auto& i: s){
        if(!v[i-'a']){
            ans += i;
            v[i - 'a'] = true;
        }
        if(ans.length() % k == 0){
            for(int i = 0; i < 26; i++){
                v[i] = false;
            }
        }
    }
    ll l = ans.length();
    if(l >= (k * n)){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
        string curr = "";
        for(int i = k - 1; i < ans.length(); i += k){
            curr += ans[i];
        }
        for(int i = 0; i < 26; i++){
            if(!v[i]){
                curr += (i + 'a');
                break;
            }
        }
        while(curr.length() < n){
            curr += 'a';
        }
        cout << curr << endl;
    }
}

int main(){
    ll t; cin >> t;
    while(t--){
        solve();
    }
}