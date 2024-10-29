#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    ll n; cin >> n;
    string s; cin >> s; s = '#' + s;
    ll cnt = 0; ll sum = 0;
    for(int i = n; i > 0; i--){
        if(s[i] == '1'){
            cnt++;
        }
        else{
            if(cnt > 0){
                cnt--;
                sum += (i);
            }
            else{
                sum += (i);
            }
        }
    }
    vector<ll> v; ll cnt1 = 0;
    for(int i = 1; i <= n; i++){
        if(s[i] == '1'){
            cnt1++;
            v.push_back(i);
        }
        if(cnt1 == cnt){
            break;
        }
    }
    int st = 0, e = v.size() - 1;
    while(st < e){
        sum += v[st];
        st++;
        e--;
    }
    if(st == e){
        sum += (v[st]);
    }
    cout << sum << endl;
}

int main(){
  ll t; cin >> t;
  while(t--){
    solve();
  }
}